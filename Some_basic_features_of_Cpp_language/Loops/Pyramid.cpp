#include <iostream>
using namespace std;
int main() {
	int rows;
	char cha;
	cin >> rows >> cha;
	for (int i = 0; i < rows ; i++ ) {
		for (int j =0; j <= i; j++) {
			cout << cha  << " ";
		}
		cout << "\n" ;
	}
	return 0;
}
		
	