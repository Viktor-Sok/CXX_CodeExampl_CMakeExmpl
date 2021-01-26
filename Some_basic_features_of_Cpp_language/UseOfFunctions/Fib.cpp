#include <iostream>
using namespace std;

void Fib(int n, int n1 = 0, int n2 = 1) {
	if (n1 <= n && n < n2) {
		cout << n1 << endl;
	}else{
		cout << n1<< " ";
		Fib(n, n2, n1+n2);
	}
}
int main() {
	int n;
	cin >> n;
	Fib(n);
	return 0;
}


		