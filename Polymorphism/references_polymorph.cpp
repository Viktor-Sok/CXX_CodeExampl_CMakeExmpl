#include <iostream>
#include <string>

using namespace std;
// Polymorphism also works with pointers (and usually does), but here given an example with references 
class Parent {
public:
    int x_;
    Parent() {x_ = 0;}; // default constructor
    Parent(int x ) : x_(x) {}
    virtual void print() {
        /*function which can be overriden by the child class*/
        cout << x_ << endl;
    }
    // virtual destructor allows to call child destructor first then parent destructor (whithout vurtual only parent destructor will be called)
    virtual ~Parent() {cout << "Parent destructor called" << endl;};
};

class Child : public Parent {
    string y_;
public:
    Child(string y) : Parent(), y_(y) {}; // Parent constructor called in initializer list
    void print() override { // ovverride specifier requaries that print myst be virtual in the parent class (avoiding mistakes)
        cout << y_ << endl;
    }
    ~Child () {cout << "Child destructor called" << endl;} // child destructor
};

void classClient(Parent& p) {
    /* This function recieves
    reference to Parent class and calls
    the method which defined by virtual table for methods*/
    p.print();
}

int main() {
    // Test on polymorphysm
    Parent p1(3);
    Child c1("name");
    classClient(p1); // print() from parent class wiil be called
    classClient(c1); // print() from the child class will be called
    return 0;
}