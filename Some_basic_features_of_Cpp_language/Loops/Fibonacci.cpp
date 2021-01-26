#include <iostream>
using namespace std;

int main (){
	int n1 = 0 , n2 = 1;
	int n;
	string ans = "0 1 ";
	cin >> n;
	while (n2 <  n) {
		ans += to_string(n1 + n2) + " ";
		int temp;
		temp = n1;
		n1 = n2;
		n2 += temp;
		
	}
	cout << ans << endl;
	return 0;
}