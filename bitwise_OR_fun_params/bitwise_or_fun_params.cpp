#include <iostream>
using namespace std;

enum : uint8_t {
    feed = 0b001,
    play = 0b010,
    walk = 0b100 
};

class Dog {
public:
    void interact(const char* dogName, uint8_t bitmask);
private:
    // define constants with different bits to use & in conditions
    // in C it's usually done as #define feed = 0b001
    // it's possible to use 16 system like #define feed = 0x01
    // also we can dfine it in enums, look above for enum defenition 
    static const uint8_t feed = 0b001;
    static const uint8_t play = 0b010;
    static const uint8_t walk = 0b100;
};

void Dog::interact(const char* dogName, uint8_t bitmask) {
    cout << "Let's go ";
    if (bitmask & feed) {
        cout << "and feed " << dogName << " ";
    }
    if (bitmask & play) {
        cout << "and play with " << dogName << " ";
    }
    if (bitmask & walk) {
        cout << "and walk " << dogName << " ";
    }
    cout << endl;
}

int main() {
    Dog dog;
    dog.interact((char*)"Bob", feed);
    dog.interact((char*)"Bob", feed|walk);
    dog.interact((char*)"Bob", feed|walk|play); // order of parameters isn't important
    return 0;
}
