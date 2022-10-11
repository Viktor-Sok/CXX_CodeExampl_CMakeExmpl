#include <iostream>
#include <fstream>
#include <thread> 
#include <mutex> // used when several threads use shared data
#include <condition_variable> // put thread in waiting mode while ther is no work to be done
#include <chrono>
#include <stdlib.h> // standard library (for strtol())
//#include <cassert> //touse assert(<bool expression>)
#include <memory> // smart pointers
#include "numbers.h"
#include "logging_thread.h"

int main(int argc, char*argv[])
{
    try
    /*cheking the number of arguments provided to main.exe in the command line */
    {
        if (argc >2) throw argc;
        // std::cout << argv[0] <<" "<< argv[1]<<std::endl;
    }
    catch(const int& argc) // catch by reference and as constant( good practice)
    {
        std::cerr << "Argument error: only one argument accepted"<< std::endl;
        return -1;
    }
    long N = std::strtol(argv[1], NULL, 10); // converting argv[1] to long integer
    std::unique_ptr<Numbers> num(new Numbers()); // smart pointer
    OutputToFile write;
    OutputToTerminal print;
    std::chrono::time_point<std::chrono::steady_clock> startTime, endTime;
    startTime = std::chrono::steady_clock::now(); // start time
    for(int i = 0; i < N; i++) 
    {
        
        // std::this_thread::sleep_for(std::chrono::microseconds(4000)); //imitation of heavy calculations before outputting to the file we can move them to the other thread
        write.writeOut(num);
        print.writeOut(num);
        num->nextNumber();
    }
    endTime = std::chrono::steady_clock::now(); // end time
    auto timeSpan = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime); //total time of the loop execution (auto type deduction)
    std::cout<<"Execution time: "<<timeSpan.count()/ 1e6 <<" seconds"<<std::endl;
    return 0;
}