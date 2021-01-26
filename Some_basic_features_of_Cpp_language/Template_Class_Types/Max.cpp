#include <iostream>
using namespace std;

template<typename Any>
Any maxElement(Any arr[], int N);



int main() {
	double arr[6] = {1.1,7.2,4.3,9.8,3.7,2.2};
	int length = sizeof(arr)/sizeof(arr[0]);
	cout << maxElement<double> (arr, length)<< endl;
	return 0;
}

template<typename Any>
Any maxElement(Any arr[], int N){
	Any max = arr[0];
	for (int i=1; i<N; i++){
		if (arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}