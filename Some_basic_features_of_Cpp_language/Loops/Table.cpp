#include <iostream>
using namespace std;
int main() {
	string ans;
	int n;
	cin >> n;
	cout << "Multiplication Table of the number "<< n << endl ;
	int i =1;
	while (i<=10) {
		int mult = i*n;
		cout << n <<" x " << i << " = " << mult <<endl;
		ans += to_string(mult) + " " ;
		i++;
	}   
	cout << ans << endl;
	return 0;
}
		
	