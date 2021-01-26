#include <iostream>
using namespace std;
void print(int* , int);
int main(){
	int N;
	cout << "Enter a number equal or grater than 2"<<endl;
	cin >> N;
	cout << 1<< endl << 1 << " "<< 1<<endl;
	
	int* p = new int[1] ; 
	*p = 1;
	int temp;
	int k;
	int i;
	for (k=0; k < N-2; k++){
		for(i=0; i<((k+2)/2); i++){
			switch (i) {
				case 0: 
					*(p+k) = *p + 1;
					temp = *p;
				    *p = *(p+k);
					//*(p+k) = *p;
					break;
				default: 
					*(p+k-i) = temp + *(p+i);
					temp = *(p + i);
					*(p+i) = *(p+k-i);
			}
		}
		print(p,k+1);
	}
	delete p;
	return 0;
}
void print(int* p, int N){
	cout << 1 <<" ";
	for (int i =0; i < N; i++){
		 cout << *(p+i) << " ";
	}
	cout << 1 <<  endl;
}

		
			
			