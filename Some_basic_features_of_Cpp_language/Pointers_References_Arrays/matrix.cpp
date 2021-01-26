#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int arr[N][N];
	for (int i=0; i<N; i++){
		for(int j =0; j<N; j++){
			if (i<j) {
				arr[i][j] = 1;
			} else if (i>j){
				arr[i][j] = -1;
			} else {
				arr[i][j] = 0;
			}
		}
	}
	for  (int k=0; k <N; k++){
		for (int l=0; l<N; l++){
			cout << arr[k][l] << " ";
		}
		cout << "\n";
	}
}