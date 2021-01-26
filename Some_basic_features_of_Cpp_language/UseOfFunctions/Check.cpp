#include <iostream>
using namespace std;
int sumCheck(int , int );
int main() {
	int n,m;
	cin >> n >> m ;
	int check = sumCheck(n,m);
	cout << "Check is " << check << '\n';
}
int sumCheck (int n, int m) {
	int sum, check;
	sum = n + m;
	if (sum < 100) {
		cout << "Sum is less than 100"<< endl;
		check = 0;
	}
	if (sum> 100){
		cout << "Sum is grater than 100"<< endl;
		check = 1;
	}
	if (sum == 100) {
		cout << "Sum is equal to 100"<< endl;
		check = 2;
	}
	return check;
}