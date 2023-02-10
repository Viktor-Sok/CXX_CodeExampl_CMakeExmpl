#pragma once
#include <iostream>
template<typename T>
class A 
{
    public:
        T x;    
        void print(); 
 
};

class B : public A<int>
{
    public:
    void setter(int);

};
class C : public A<char>
{
    public:
    void setter(char);

};

#include "print.cpp"

