#include <iostream>
#include <string>
using namespace std;

class Animal {
	protected:
	int age;
	string name;
	public:
	void set_data(int a, string b){age = a; name = b;}

};
class Zebra : public Animal {
	public:
	string who() {
		string str;
		str += "The Zebra named ";
		str += name;
		str +=" is ";
		str += to_string(age);
		str += " years old.\n";
		return str;
	}
};
class Dolphin : public Animal{
	public:
	string who() {
		string str;
		str += "The Dolphin named ";
		str += name;
		str +=" is ";
		str += to_string(age);
		str += " years old.\n";
		return str;
	}
};
int main() {
	Zebra Ana;
	Ana.set_data(20, "Ana");
	Dolphin Jim;
	Jim.set_data (10, "Jim");
	cout << Ana.who() ;
	cout << Jim.who() ;
}
	
