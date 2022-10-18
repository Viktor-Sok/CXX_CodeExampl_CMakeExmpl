#include <iostream>
//#include "fun.h"
#include "dif.h"
#include "fun.h" // API from static library
using namespace std;

int main() {
    cout << sum1(3,4) << endl;
    cout << dif(3,4) << endl;
    getchar();
    return 0;
}