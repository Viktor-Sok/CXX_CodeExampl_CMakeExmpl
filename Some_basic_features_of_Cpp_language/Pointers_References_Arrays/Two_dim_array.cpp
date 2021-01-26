#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int arr[N][N];
	for (int i=0; i<N; i++){
		for(int j =0; j<N; j++){
			arr[i][j] = j+1 + N*i;
		}
	}
	for  (int k=0; k <N; k++){
		for (int l=0; l<N; l++){
			cout << arr[k][l] << " ";
		}
		cout << "\n";
	}
}
			