#include <iostream>
using namespace std;
int *sortArg(int* , int);
int main(){
	int N;
	cin >> N;
	int arr[N];
	for (int i =0; i<N; i++){
		cin >> arr[i];
	}
	int *p;
	int *pp;
	p = arr;
	cout << p << endl;
	for (int i = 0; i<N; i++ ){
		cout << (p + i) << " "<<endl;
	}
	pp = sortArg(p , N);
	for (int i = 0; i<N; i++ ){
		cout << *(pp + i) << " "; //dereferencing the array values pointed to by pointer p
	}
	cout << endl;
	for (int i = 0; i<N; i++ ){
		cout << (pp + i) << " "<< endl;
	}
}

int *sortArg(int *p, int N){
	int temp;
	for (int i=0; i < N-1; i++){
		for (int j = i+1; j < N; j++){
			if (*(p + i) > *(p + j)){
				temp = *(p +i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
	return p;
}
	
	