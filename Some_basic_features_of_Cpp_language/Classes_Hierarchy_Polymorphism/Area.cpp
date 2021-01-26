#include <iostream>
using namespace std;

class Area {
	public:
	Area (double l, double h) { length = l; hight = h;} // constructor
	//Area() {length = 0; hight = 0;} default constractor
	double calcArea(){return length*hight/2;} // member function
	private:
	double length, hight; // private mamber variables
};
int main(){
	double l,h;
	cin >> l >> h;
	Area triangle(3,5); // creating the instance of the class Area that is object
	cout << triangle.calcArea()<< endl; // accessing member function 
	return 0;
}
