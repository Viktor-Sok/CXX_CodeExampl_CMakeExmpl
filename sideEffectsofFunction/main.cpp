#include <iostream>

using namespace std;

int* fun6(int& ra) {
    // this function  can be used to change 
    // referenced variable with or without assignment
    ra = 6;
    return &ra;
}

int& fun5(int* pa) {
    // combination of fun3 and fun4
    *pa = 5;
    return *pa;
}


int* fun4(int* pa) {
    // analog to fun3
    *pa = 4;
    return pa;
}

int& fun3(int& ra) {
    // this function  can be used to change 
    // referenced variable with or without assignment
    ra = 3;
    return ra;
}

void fun2(int& ra) {
    // analog to fun 1
    ra = 2;
}
void fun1(int* pa) {
    // side effect for the corresponding variable
    *pa = 1;
}

int main() {
    int a = 0;
    int* pa = &a;
    fun1(pa);
    cout << a << endl;
    fun2(a);
    cout << a << endl;
    fun3(a);
    cout << a << endl;
    cout << *fun4(pa) << endl;
    cout << fun5(pa) << endl;
    cout << *fun6(a) << endl;
    return 0;
}