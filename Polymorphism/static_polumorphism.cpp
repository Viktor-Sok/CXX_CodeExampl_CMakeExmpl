#include <iostream>
#include <string>
#include <vector>

using namespace std;
//CRTP(Curiosly Recurring Template Pattern) for implememnting static polymorphism

template<typename Child>
class Animal {
public:
    void voice() {
        static_cast<Child*>(this) -> voice_impl();
    }
};
class Dog : public Animal<Dog>{
public:
    void voice_impl() {
        cout << "AvAvAv" << endl;
    }
};
class Cat : public Animal<Cat>{
public:
    void voice_impl() {
        cout << "MrMrMr" << endl;
    }
    
};

template<typename T>
void classClient(T& t) {
    t.voice(); // polymorphism happens here
}

int main() {
    cout << "Calling methods from the corresponding objects: " << endl;
    Dog d; Cat c;
    d.voice();
    c.voice();
    cout << "Calling from the Client function: " << endl;
    classClient(d); 
    classClient(c);
    return 0;
}