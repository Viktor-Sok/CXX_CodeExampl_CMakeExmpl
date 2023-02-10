#include <iostream>
template<typename T>
void A<T>::print() 
{
    std::cout << x << std::endl; 
};

void B::setter(int n)
{
    x = n;
}
void C::setter(char ch)
{
    x = ch;
}


