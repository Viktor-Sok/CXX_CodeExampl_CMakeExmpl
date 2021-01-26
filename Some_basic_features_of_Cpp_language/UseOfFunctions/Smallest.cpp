#include <iostream>
using namespace std;

template<typename T>
int index_of_smallest(T arr[],int N, index = 0){
	for (int i =1 i<N; i++){
		if (arr[i]< arr[index]){
			index = i;
		}
	}
	return index;
}

int main() {
	int arr[] = {2,4,1,6,4,7};
	int length = sizeof(arr)/size0f(arr[0]);
	cout << index_of_smallest<int>(arr, length)<<endl;
	return 0;
}
