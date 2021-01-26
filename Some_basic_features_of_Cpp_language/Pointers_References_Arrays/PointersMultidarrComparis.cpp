#include <iostream>
using namespace std;
int main(){
	int arr[2][2] = {{1,2},{3,4}};
	int a = 5;
	int *p; int  **ptp;
	p = &a;
	ptp = &p;
	
	//int *p;
	//p = &a;
	cout << arr <<" "<< arr[1] << " " << arr[1][0]<< endl;
	cout << a << " "<< p<<" " << *p << " "<< ptp << " " 
		<< *ptp << " " << **ptp << endl;
}
