#include <iostream>
using namespace std;
class Complex
{
public:
	Complex(double real, double image);
	Complex(Complex& another);
	void printComplex();
	//实现+操作运算符，如果需要连续加，如a + b + c 就不能返回引用。
	Complex operator+(Complex& another);

	~Complex();

private:
	double real;
	double image;
};

Complex::Complex(double real, double image)
{
	this->real = real;
	this->image = image;
}
Complex::Complex(Complex& another)
{	
	this->real = another.real;
	this->image = another.image;
	cout << "Copy constructor called" << endl;
}
void Complex::printComplex()
{
	cout << "image = " << image << " real = " << real << endl;
}
Complex Complex::operator+(Complex& another)
{
	Complex Ctemp(real + another.real, image + another.image);
	return Ctemp;
}
Complex::~Complex()
{
}
int main()
{
	Complex C1(10, 20);
	Complex C2(20, 30);
	C1.printComplex();
	C2.printComplex();
	Complex C3 = C1;
	C3.printComplex();
	C3 = C1 + C2 + C1;
	C3.printComplex();
	return 0;
}
