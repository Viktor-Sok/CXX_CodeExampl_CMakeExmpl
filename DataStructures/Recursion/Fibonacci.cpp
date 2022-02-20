#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
int fib(int n){
	//recursive function for Fibbonacci number
	if (n==0) return 0;
	if (n==1) return 1;
	return fib(n-1) + fib(n-2);
}
*/

/*
long int fib(long int n){
	//loop function for Fibonacci number
	long int prev1 = 0;
	long int prev2 = 1;
	long int temp;
	for(int i=0; i < n; i++){
		temp = prev1 + prev2;
		prev1 = prev2;
		prev2 = temp;
	}
	return prev1;
}
*/

/*
long int fib(int n){
	//using array for storing results1
	static long int *A = new long int[n];
	
	if (n == 0) {
		A[0] = 0;
		return 1;
	}
	A[n] = fib(n-1);
	
	return A[n-1] + A[n];
}
*/
int A[5];


long int fib(int n){
	//using array for storing results2
	if(n<=1) {
		A[n]= n;
		return n;
	}
	if(A[n-1] == -1) A[n-1] = fib(n-1);
	if(A[n-2] == -1) A[n-2] = fib(n-2);
	return A[n-1] + A[n-2];
}

int main(){
	memset(A, -1, sizeof(A) );
	int n = 5;
	cout << n <<"-th number of Fibonacci series is: "<< fib(n)<<endl;
	return 0;
}
