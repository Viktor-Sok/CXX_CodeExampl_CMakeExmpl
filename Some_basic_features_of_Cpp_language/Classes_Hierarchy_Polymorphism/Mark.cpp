#include <iostream>
using namespace std;

class Student {
	public:
	Student (); //default constractor
	Student (string, double, double);
	double getMarks(int);
	double averageMark();
	private: // private member variables
	string Name;
	double mark1, mark2;
};

int main(){
	string Name;
	double m1, m2;
	cin >> Name >> m1 >> m2;
	Student average(Name, m1, m2);
	cout << average.getMarks(1) << endl;
	cout << average.averageMark() << endl;
	Student av2;
	cout << av2.getMarks(1) << endl;
	cout << av2.averageMark()<< endl;
}
	


Student :: Student(){
	Name = "null";
	mark1 = 0;
	mark2 = 0;
}
Student :: Student (string a, double b, double c){
	Name = a;
	mark1 = b;
	mark2 = c;
}
double Student :: getMarks (int n){
	if (n==1){
		return mark1;
	}else{
		return mark2;
	}
}
double Student :: averageMark() {
	return (mark1 + mark2)/2;
}