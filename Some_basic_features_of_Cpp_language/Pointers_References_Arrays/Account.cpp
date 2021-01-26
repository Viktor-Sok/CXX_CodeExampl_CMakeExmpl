#include <iostream>
using namespace std;
//const int account = 0, withdraw = 0, deposit = 0;
void (*w)(double*, double);
void (*d)(double*, double);


void dep(double* pta, double deposit ){
	*pta += deposit;
}

void withd(double* pta, double withdraw ){
	if (withdraw > *pta){
		cout << "You are broke. You don’t have enough money. Go away\n";
	}else{
		*pta-= withdraw;
	}
}
int main(){
	double account,withdraw , deposit;
	cout << "Enter the acccount, withdraw and deposit\n";
	cin >> account >> withdraw >> deposit;
	double* pta;
	pta = &account; // Pointer to the account variable
	w = &withd;
	d = &dep;
	w(pta, withdraw);
	cout <<"Remains "<< *pta <<  endl;
	d(pta, deposit);
	cout<<"New balance "<< *pta << endl;
	return 0;
}
	