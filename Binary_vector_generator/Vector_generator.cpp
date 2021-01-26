#include <iostream>
#include <stdlib.h>  
#include <time.h>
#include <fstream>
using namespace std;

int main() {
	cout << "Enter a number and dimension of  vectors\n";
	srand (time(NULL));
	int N,D;
	cin >>N>>D;
	char fileName[80];
	cout << "Type filename including format\n";
	cin >> fileName;
	ofstream textFile(fileName);
	//short int vectors[D][N];
	int i,j;
	for (i=0; i<N; i++){
		for(j=0; j< D; j++){
			textFile << rand() % 2;
		}
		textFile << endl;
	}
	textFile.close();
	return 0;
}


