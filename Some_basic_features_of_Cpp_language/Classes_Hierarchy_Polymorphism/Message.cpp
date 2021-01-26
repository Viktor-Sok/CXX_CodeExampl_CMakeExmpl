#include <iostream>
#include <string>
using namespace std;

class Mammal{
	protected:
	int age;
	public:
	Mammal(int n) {age = n;}
	virtual void Eat();
	virtual void Speak();
	virtual int getAge();
};
class Dog : public Mammal{
	public:
	Dog(int n) : Mammal(n) {age = n;}
	void Eat();
	void Speak();
	int getAge();
};
class Cat : public Mammal{
	public:
	Cat(int n) : Mammal(n) {age = n;}
	void Eat();
	void Speak();
	int getAge();
};

void Mammal :: Eat(){cout << "Mammal eats food\n";}
void Mammal :: Speak(){cout << "Mammal speaks mammalian!!\n";}
int Mammal :: getAge(){return age;}

void Dog :: Eat(){cout << "Dog eats food\n";}
void Dog :: Speak(){cout << "Dog speaks Dogian!!\n";}
int Dog :: getAge(){return age;}

void Cat :: Eat(){cout << "Cat eats food\n";}
void Cat :: Speak(){cout << "Cat speaks Catian!!\n";}
int Cat :: getAge(){return age;}

int main() {
	Mammal* m;
	Mammal ma(2);
	Dog d(4);
	Cat c(3);
	m = &ma; 
	cout << m -> getAge() << endl;  m -> Eat(); m ->Speak();
	m = &d;
	cout << m -> getAge() << endl;  m -> Eat(); m ->Speak();
	m = &c;
	cout << m -> getAge() << endl;  m -> Eat(); m ->Speak();
	
}
	