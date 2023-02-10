#include <iostream>
#include "print.h"

int main() 
{
    B b;
    C c;
    b.setter(3);
    c.setter('a');
    b.print();
    c.print();
    return 0;
}