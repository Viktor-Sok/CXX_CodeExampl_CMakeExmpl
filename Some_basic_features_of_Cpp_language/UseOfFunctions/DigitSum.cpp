#include <iostream>
using namespace std;
int digSum( int );

int main() {
	int n;
	cin >> n;
	cout << "Sum of digits is "<< digSum(n)<< endl;
}
int digSum(int n){
	if (n%10 == 0){
		return n;
	}else{
		return n%10 + digSum((n - n%10)/10);
	}
}
	