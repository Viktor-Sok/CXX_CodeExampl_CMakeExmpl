#include <iostream>
#include <iomanip> //io_manipulation
#include "conio.h" // console_io
#include <fstream>
using namespace std;

int main(){
	int arr[][4]= {{1,0,1,0},{0,0,1,1},{1,1,0,1},{0,1,0,1}};
	char name[8]= "Lol.txt"; // there is end symbol \o in name[7]
	ofstream mine(name,ios::app);
	int i,j;
	for (i =0; i<4; i++){
		for (j =0; j<4; j++){
			mine << arr[i][j] << " ";
		}
		mine << endl;
	}
	mine.close();
	return 0;
}
		
