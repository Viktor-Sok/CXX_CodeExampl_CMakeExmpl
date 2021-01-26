#include <iostream>
using namespace std;

template <typename Any>
class Mult {
	public:
	Mult (Any a, Any b) {x = a; y = b;};
	Any mult();
	Any x,y;
};




template <typename Any>
Any Mult<Any> :: mult() {return x*y;} //defining function

int main() {
	Mult<double> object(3,4);
	cout << object.x << " "  << endl;
	cout << object.y << " " << endl;
	cout << object.mult()<< endl;
}
