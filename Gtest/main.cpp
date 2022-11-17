#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "fun.h"
using namespace std;

int main(int argc, char* argv[]) {
    switch (argc) {
        case 1:
        {
            // run without console parameters (the only parameter is the name of the program itself)
            cout << "Build in the program values: " << fun(2, 3) << endl;
            break;
        }
        case 2:
        {
            // read data from a file
            ifstream f(argv[1]);
            if (!f.is_open()) 
                throw runtime_error("Problem with opening the file");
            int a, b;
            while(f >> a >> b) {
                
                if (!f.good())
                    throw runtime_error("Problem with reading the file");
            }
            f.close();
            cout << "From file: " << fun(a, b) << endl;
            break;
        }
        case 3:
        {
            // read data from console parameters
            int a = stoi(argv[1]);
            int b = stoi(argv[2]);
            cout << "From console: "<< fun(a, b) << endl;
            break;
        }
        default:
            throw runtime_error("Wrong number of arguments");
    } 

    return 0;
}