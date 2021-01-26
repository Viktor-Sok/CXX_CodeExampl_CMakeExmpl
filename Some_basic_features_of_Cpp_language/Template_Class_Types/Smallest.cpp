#include <iostream>
using namespace std;

template<typename T>
int index_of_smallest(T arr[],int N, int index = 0){
	for (int i =1; i<N; i++){
		if (arr[i]< arr[index]){
			index = i;
		}
	}
	return index;
}

int main() {
	int arr[] = {2,4,3,6,7,1};
	int length = sizeof(arr)/sizeof(arr[0]);
	cout << index_of_smallest<int>(arr, length)<<endl;
	return 0;
}
