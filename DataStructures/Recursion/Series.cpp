#include <iostream>
using namespace std;

float partialSum(float, int);

int main(){
	int n = 20; // number of series terms
	float x = 5; // point at which the exponent is approximated by the series
	cout <<"Sum of "<<n<<
	" terms of series at the point "<<x<<" is: "<< partialSum(x,n)<<endl; 
	 
	return 0;
}

float partialSum(float x, int n){
	static float T = 1, S = 0.0;
	if (n==0) return T;
	S = partialSum(x, n-1);
	T *= x/n;
	return S + T;
}
