#include <iostream>
#include <iomanip>
#include "conio.h"
using namespace std;

int main(){
	int m;
	cout << "Enter array size:\n";
	cin>>m;
	string arr[m];
	cout <<"Enter array elements:\n";
	int len = sizeof(arr)/sizeof(string);
	int i = 0;
	while(i<len){
		
		cin>>arr[i];
		i++;		
	}
	//plotting a table
	
	for(int i=0; i < len ; i++){
		if ((i+1)%4==0) cout<<endl;
		cout<< setw(5)<<setfill('*')<< arr[i]<< " ";
	}

	getch();
	return 0;
}
