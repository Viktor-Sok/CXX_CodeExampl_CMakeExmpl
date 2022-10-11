#ifndef LOGGING_THREAD_H
#define LOGGING_TREAD_H

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue> // queue as a buffer for storing data in the thread
#include "numbers.h"
#include <memory> // smart pointers
//#include <functional> // to pass function as a pointer using std::function<rtype(type, type)> func_name syntax
inline std::size_t numberOfCores = 8; // number of cores on your machine
class LoggingThread
/* implememtation of one thread in the class*/
{
    private:
        static std::size_t _count; // to restrict number of threads to 2*number_of_cores (initialization in .cpp ISO)
        LoggingThread(const LoggingThread&) = delete; // delete copy constructor (forbid copuing the objects)
    protected:
        // std::string filename = "natural_numbers.txt";
        std::thread th1; // tread object
        std::mutex mtx; // mutex object
        std::condition_variable cv; // cond variable to implement waiting for the thread
        std::queue<int> dataToWrite; // buffer to recieve data by thread for processing and when not empty - thread wakes up.
        bool ready = false; // indicates when thread has finished its job (used in the destructor of thread)
        //void _methodRunInThread(std::function<void(std::ofstream&, std::queue<int>&)> func); // method where the heavy calculations and file output happen (recieves poiinter to a function)
        void stop(); // this function is used by destructor of thread object
        
    public:
        LoggingThread();
        ~LoggingThread();
        void writeOut(std::unique_ptr<Numbers>& num); // recieves data from main and appends to queue 
        //void _methodRunInThread(/*std::function<void(/*std::ofstream&, std::queue<int>&)> func*/); // method where the heavy calculations and file output happen (recieves poiinter to a function)
        
};

class OutputToFile : public LoggingThread
{
    private:
        std::ofstream _file; // object for creating and appending to the output file
        void _methodRunInThread(); // method where the heavy calculations and file output happen 
    public:
         OutputToFile();
        ~OutputToFile();
        
};

class OutputToTerminal : public LoggingThread
{
    private:
        void _methodRunInThread(); // method where the heavy calculations and terminal otput happens
    public:
         OutputToTerminal();
        ~OutputToTerminal();
};

#endif /*LOGGING_THREAD_H*/