//#include <iostream>
//using namespace std;

template<typename T>
int index_of_smallest(T arr[],int N, int index ){
	for (int i = index + 1; i<N; i++){
		if (arr[i]< arr[index]){
			index = i;
		}
	}
	return index;
}


