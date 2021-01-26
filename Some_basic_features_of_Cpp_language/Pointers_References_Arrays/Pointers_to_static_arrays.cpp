#include <iostream>
using namespace std;
int main(){
	int arr[4];
	int *p;
	p = arr;
	*p = 1;
	p++;
	*p =2;
	p = &arr[2];
	*p =3;
	*(p+1) = 4;
	for (int i = 0; i<4; i++) {
		cout << arr[i]<<" " << endl;
	}
}
	