#include <iostream>
using namespace std;
void calcCube(int& k, int& l, int& m){
	k = k*k*k;
	l = l*l*l;
	m = m*m*m;
}
int main() {
	int k,l,m;
	cin>>k>>l>>m;
	calcCube(k,l,m);
	cout << "The cubed values are "<< k<<" "<<l<<" "<<m<<endl;
}