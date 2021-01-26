#include <iostream>
#include <stdlib.h>  
#include <time.h>
#include <fstream>
#include <conio.h>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
using namespace std;

//Prototypes of the functions that was used
bool* readInData(int& , int& );
int binomialCoefficients(int , int );
void getWeight(bool* , unsigned long **, int  );
void readOutData(unsigned long **, int);
bool*  vectorXOR(const bool *, const bool *, int );
void getNewIndexes(int*, const int*, const int);
void getNewGroups(int * , const int );
void copyArray(bool **, bool** , int ,int );

//The  algorithm is implemented in main()
int main(){
	bool *ptInputVectors;
	int numberOfVectors = 0, lengthOfVector = 0;
	ptInputVectors = readInData(numberOfVectors, lengthOfVector);
	//Calculating (k, k/2) binomial coefficient for
	//determining the max array size which is required to store values during iterations
	unsigned long Nmax = binomialCoefficients(numberOfVectors, numberOfVectors/2);
	bool **storedVectors = new bool*[Nmax];
	
	for (int i =0; i< Nmax; i++){
		storedVectors[i] = new bool[lengthOfVector];
	}
	bool **tempStoredVectors = new bool*[Nmax];
	for (int i =0; i< Nmax; i++){
		tempStoredVectors[i] = new bool[lengthOfVector];
	}
	
	
	//Declraring and Initializing weight-number array using pointer to pointer
	unsigned long **ptpOutputWeights = new unsigned long *[lengthOfVector + 1];
	for (int i =0; i<lengthOfVector + 1; i++ ){
		ptpOutputWeights[i] = new unsigned long [2];
		ptpOutputWeights[i][0] = i;
		ptpOutputWeights[i][1] = 0;
		
	}
	//n=0 Outputting trivial linear combination
	ptpOutputWeights[0][1] = 1;
	//n=1 Declaring and Initializing the variables needed to start the iterations
	int *groups, *indexes;
	groups = new int[numberOfVectors];
	indexes =  new int[numberOfVectors];
	for (int i=0; i <numberOfVectors; i++){
		groups[i] = numberOfVectors - i - 1;
		indexes[i] = i;
		for(int j=0; j <lengthOfVector; j++ ){
			storedVectors[i][j] = ptInputVectors[i*lengthOfVector+j];
		}
		getWeight( &storedVectors[i][0], ptpOutputWeights, lengthOfVector);
	}
	bool *vector;
	//n=2  Start of the iterations (3 nested for loops)
	for (int n = 2; n <= numberOfVectors; n++){ //number of the ones in beta vector
		unsigned long m = 0; // index for counting vectors in tempStoredVectors
		for(int i=0; i < numberOfVectors - n +1; i++ ){ // the whole group
			for(int j =0; j < groups[i]; j++){//vectors obtained by using the j-th input vector
				vector = vectorXOR(&ptInputVectors[i*lengthOfVector], &storedVectors[indexes[i+1]+j][0], lengthOfVector);
				for(int k=0; k<lengthOfVector; k++){
					tempStoredVectors[m][k] = vector[k];
				}
				delete vector;
				getWeight( &tempStoredVectors[m][0], ptpOutputWeights, lengthOfVector);
				m++;
				
			}
			 
		}
		copyArray(storedVectors, tempStoredVectors, m, lengthOfVector);
		getNewIndexes(&indexes[0], &groups[0], numberOfVectors);
		getNewGroups(&groups[0],numberOfVectors );
	}
	readOutData(ptpOutputWeights, lengthOfVector);
	delete ptInputVectors, storedVectors, tempStoredVectors, ptpOutputWeights,
	groups, indexes;
	cout<<"Press any key to exit...\n";
	getch();
	return 0;
}

//functions' defenitions
bool* readInData(int& numberOfLines, int& lengthOfLine ){
	//This function reads vectors from the input file
	char  fileName[80];
	ifstream textFile_1;
	
	do {
		cout << "Enter filename including format of the file: \n" << flush;
		cin >> fileName;
		textFile_1.open(fileName,ios_base::out);
		if (!textFile_1)  cout<<"File doesn't exist\n" ;
	}  while(!textFile_1);
	
	// determining number of vectors (lines in the input file),
	// and length of a vector (length of a line in the input file)
	string line;
	numberOfLines = 1;
	getline(textFile_1,line);
	lengthOfLine = line.length();
	for (int i = 0; getline(textFile_1,line); numberOfLines++){
		if (line == "") numberOfLines--; 
	};
	textFile_1.close();
	
	//Reading in the data from the input file
	ifstream textFile(fileName);
	bool *ptInputVectors = new bool[numberOfLines*lengthOfLine];
	char charLine[numberOfLines+1];
	for (int i =0; i <numberOfLines; i++){
		getline(textFile,line);
		strcpy(charLine,line.c_str());
		for (int j=0; j < lengthOfLine; j++ ){
			*(ptInputVectors + i*lengthOfLine +j) = (int)charLine[j]-'0';
		}
	}
	cout <<"Number of the vectors is: "<<numberOfLines<<endl;
	cout << "Length of an individual vector is: "<<lengthOfLine<<endl;
    textFile.close();
	
	return  ptInputVectors;//returning pointer
}

int binomialCoefficients(int n, int k) {
	//calculating (n,k) binomial coefficient
   int C[k+1];
   memset(C, 0, sizeof(C));
   C[0] = 1;
   for (int i = 1; i <= n; i++) {
      for (int j = min(i, k); j > 0; j--)
         C[j] = C[j] + C[j-1];
   }
   return C[k];
}



void getWeight(bool *ptVector, unsigned long **ptpOutputWeights, int N ){
	int weight = 0;
	for (int j =0; j <N; j++){
		weight += *(ptVector+j);
	}
	ptpOutputWeights[weight][0] = weight;
	ptpOutputWeights[weight][1] += 1;
}

void readOutData(unsigned long **ptpOutputWeights, int lengthOfVector){
	ofstream weightsOut ("WeightTable.txt");
	cout<< "Table of number of vectors with certain weight:\n";
	cout<< " "<<endl;
	cout <<setw(10)<<"weight"<<setw(10) << "vectors"<<endl;
	for (int i =0; i < lengthOfVector + 1; i++){
		if (ptpOutputWeights[i][1] != 0){
			weightsOut << ptpOutputWeights[i][0] <<"\t"<< ptpOutputWeights[i][1]<<endl;
			cout <<setw(10)<< ptpOutputWeights[i][0] << setw(10)<< ptpOutputWeights[i][1]<<endl;
		}
	}
	cout<< " "<<endl;
}

bool*  vectorXOR(const bool *vectorA, const bool *vectorB, int lengthOfVector){
	bool *vectorC = new bool[lengthOfVector];
	for (int i = 0; i < lengthOfVector; i++){
		vectorC[i] = vectorA[i] ^ vectorB[i];
	}
	return vectorC;
}

void getNewIndexes(int * ptIndexes , const  int * ptGroups, const int numberOfVectors){
	for (int k = 1; k < numberOfVectors; k++){
		ptIndexes[k] = ptIndexes[k-1] + ptGroups[k-1];
		if (ptGroups[k]==1) break;
		
	}
}

void getNewGroups(int * ptGroups, const int numberOfVectors ){
	ptGroups[0] = 0;
	for (int k = 1; k < numberOfVectors; k++){
		ptGroups[0] += ptGroups[k]; 
		if (ptGroups[k]==1) break;
	}
	for (int k = 1; k < numberOfVectors; k++){
		if (ptGroups[k]==1) break;
		ptGroups[k] = ptGroups[k-1] - ptGroups[k];
		
	}
}

void copyArray(bool **newp, bool** p, int rows,int cols){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			newp[i][j] = p[i][j]; 
		}
	}
}
	


