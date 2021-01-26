#include <iostream>
#include "Swap_elements_module.cpp"
#include "Index_of_smallest_module.cpp"
using namespace std;

template <typename T>
void sort(T arr[], int N){
	for (int i = 0; i <N; i++) {
    	int ind = index_of_smallest<T>(arr, N, i);
		swappingValues(arr[i], arr[ind]);// works both ways - with and without <T> tag.
	}
}

int main(){
	int arr1[] = {7,6,5,4,3,2,1};
	double arr2[] = {7.1,6.4,5.4,3.2,2.1,1.1};
	int length1 = sizeof(arr1)/ sizeof(arr1[0]);
	int length2 = sizeof(arr2)/ sizeof(arr2[0]);
	sort<int>(arr1, length1);
	sort<double> (arr2, length2);
	for (int i =0; i<length1; i++){
		cout << to_string(arr1[i])<< " ";
	}
	cout << endl;
	for (int j =0; j<length2; j++){
		cout << to_string(arr2[j])<< " ";
	}
	cout<< endl;
	return 0;
}