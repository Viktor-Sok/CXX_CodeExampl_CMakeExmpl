#include <iostream>
using namespace std;
int main(){
	float a,b,ans;
	char op;
	loop: cout << "Calculate +, -, /, * of two numbers"<< endl;
	cin >> a >> op >> b;
	switch (op) {
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a-b;
			break;
		case '*':
			ans = a*b;
			break;
		case '/':
			ans = a/b;
			break;
		default:
			cout<< "Wrong operand" << endl;
			goto fin;
	}
	
	cout << "Answer is "<<ans << endl;
	goto loop;
	fin: return 0;
}