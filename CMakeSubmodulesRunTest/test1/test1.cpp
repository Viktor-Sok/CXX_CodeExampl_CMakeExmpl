#include <cassert>
#include <iostream>
#include "fun.h"


void test1() {
    assert(("Test Failed", sum1(3,4) == 6)); 
    std::cerr << "Tests OK" << std::endl;
}

int main() {
    test1();
    return 0;
}