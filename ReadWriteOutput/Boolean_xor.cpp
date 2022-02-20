#include <iostream>
using namespace std;

int main(){
	bool arr1[] = {true,true,false,true};
	bool arr2[] = {false, true, false, true};
	for (int i=0; i<sizeof(arr1); i++){
		arr1[i] = arr1[i]^arr2[i]; //xor operator
		cout << arr1[i]<<" ";
	}
	return 0;
}
