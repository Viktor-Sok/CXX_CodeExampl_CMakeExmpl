#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "logging_thread.h"
#include "numbers.h"
#include <chrono>
#include <memory> // smart pointers
#include <exception> // standard exceptions (bad_alloc, runtime_error, logical_error, etc.)
//#include <functional> // to pass function as a pointer using std::function<rtype(type, type)> func_name syntax
std::size_t LoggingThread::_count = 0; // initialization of non-const static variable
LoggingThread::LoggingThread() 
{
  ++_count;
  if(_count==numberOfCores) throw std::runtime_error("The number of threads available on this machine has been exceeded");
  ready = true;
}
LoggingThread::~LoggingThread()
{
    --_count;
}

void OutputToFile::_methodRunInThread() 
{
    for(;;)
    {
        std::unique_lock<std::mutex> lock(mtx);  // here is the unique_lock (in the function that runs in the thread)
        cv.wait(lock,[this](){return !ready  || !dataToWrite.empty();}); // lambda function is used [](){}
        if(!dataToWrite.empty())
        {
            std::this_thread::sleep_for(std::chrono::microseconds(4000)); //imitation of heavy calculations before outputting to the file
            _file << dataToWrite.front() << std::endl; //return front element in the queue
            dataToWrite.pop(); // delete front element from the queue
        }
        else if (!ready) // reaches only when destructors is called
        { 
            std::cout<<"File is ready" << std::endl;
            return;
        }
    }
    
}
void LoggingThread::stop()
{
    /* quit infinite loop in thread, use for destructor*/
    std::lock_guard<std::mutex> lock(mtx); // here is the lock_guard (used in main thread)
    ready = false;
    cv.notify_one(); // notify the thread from the main thread
}
void LoggingThread::writeOut(std::unique_ptr<Numbers>& num)
{
     std::lock_guard<std::mutex> lock(mtx); // lock mutex e.i. only main thread can access shared variables
    dataToWrite.push(num->num); // accesing data member of num object
    cv.notify_one(); // waking up the other thread
}

OutputToFile::OutputToFile()
{
    std::string filename;
    getline(std::cin, filename);
    filename+=".txt";
    remove(filename.c_str());
    _file.open(filename, std::ios::app);
    th1 = std::thread(&OutputToFile::_methodRunInThread, this); // reference to object this must be explicitly passed, actually it\s implicitally passed for all non-static methods
    std::cout<<"OutputToFile thread started"<< std::endl;
}

OutputToFile::~OutputToFile()
{
    if (th1.joinable())
    {
        stop();
        th1.join();
        _file.close();
    }
    std::cout<<"OutputToFile thread stopped"<< std::endl;
}

OutputToTerminal::OutputToTerminal()
{
    th1 = std::thread(&OutputToTerminal::_methodRunInThread, this);
    std::cout<<"OutputToTerminal thread started" <<std::endl;
}
OutputToTerminal::~OutputToTerminal()
{
    if (th1.joinable())
    {
        stop();
        th1.join();
    }
    std::cout<<"OutputToTerminal thread stopped"<< std::endl;
}
void OutputToTerminal::_methodRunInThread() 
{
    for(;;)
    {
        std::unique_lock<std::mutex> lock(mtx);  // here is the unique_lock (in the function that runs in the thread)
        cv.wait(lock,[this](){return !ready  || !dataToWrite.empty();}); // lambda function is used [](){}
        if(!dataToWrite.empty())
        {
            std::this_thread::sleep_for(std::chrono::microseconds(4000)); //imitation of heavy calculations before outputting to the file
            std::cout << dataToWrite.front() << std::endl; //return the front element of a queue
            dataToWrite.pop(); // delete front element from the queue
        }
        else if (!ready) // reaches only when destructors is called
        { 
            return;
        }
    }
}
    