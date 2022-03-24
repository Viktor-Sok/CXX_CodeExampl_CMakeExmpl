#include <iostream>
#include <array>
using namespace std;

Any maxElement(Any, int);

int main() {
	int arr[] = {1,7,4,9,3,2};
	cout << maxElement(arr, arr.size());
	return 0;
}

template<typename Any> // generic function - accepts all numeric data types
Any maxElement(Any arr[], int N){
	Any max = arr[0];
	for (int i=1; i<N; i++){
		if (arr[i]>max){
			max = arr[i];
		}
	}
	return max;
}
