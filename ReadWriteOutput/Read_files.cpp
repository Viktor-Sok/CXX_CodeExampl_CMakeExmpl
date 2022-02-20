#include <iostream>
#include <iomanip> //io_manipulation
#include "conio.h" // console_io
#include <fstream>
using namespace std;

int main(){
	int arr[4][4];
	ifstream mine("Lol.txt");
	if (!mine) cout << "No file in the directory\n";
	int i,j;
	for (i =0; i<4; i++){
		for (j =0; j<4; j++){
			mine >> arr[i][j];
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	mine.close();
	return 0;
}
