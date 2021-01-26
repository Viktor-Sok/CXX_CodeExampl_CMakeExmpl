#include <iostream>
using namespace std;

template<typename T>
class Complex{
	public:
	Complex(T& m, T& n) {real =m; imag = n;}
	void get_real() {cout<< "The real part of the complex number is " << 
		real << endl;}
	void get_imaginary() {cout<< "The imaginary part of the complex number is " << 
		imag << endl;}
	private:
	T real, imag;
};
int main() {
	double m,n;
	cin >> m >> n;
	Complex<double> z(m,n);
	z.get_real();
	z.get_imaginary();
}
