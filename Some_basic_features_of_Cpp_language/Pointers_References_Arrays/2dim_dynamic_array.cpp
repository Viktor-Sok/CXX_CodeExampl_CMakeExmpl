#include <iostream>
using namespace std;
void printBoard(int** ptp, int x, int y){
	for (int i =0; i<x; i++){
		for (int j=0; j<y; j++){
			ptp[i][j] = 1;
			cout << ptp[i][j]<< " ";
		}
		cout << endl;
	}
}
void makeBoard(int x, int y) {
	int** ptp = new int*[x];
	for (int i =0; i< x; i++){
		ptp[i] = new int[y];
	}
	printBoard(ptp,x,y);
}
int main(){  
	int x,y;
	cin >> x >> y;
	makeBoard(x,y);
	return 0;
}
