#include <iostream>
using namespace std;

template<typename T>
void swappingValues(T& x, T& y){
	T temp;
	temp = x;
	x = y;
	y = temp;
}
	

int main() {
	int m,n;
	double a,b;
	cin >> m >> n >> a >> b;
	string str;
	swappingValues<int>(m,n);
	swappingValues<double>(a,b);
	str = to_string(m) + " "+ to_string(n) + " " + to_string(a) + " "+ to_string(b);
	cout <<  str << endl;
	return 0;
}

