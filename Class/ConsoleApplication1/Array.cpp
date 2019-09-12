#include <iostream>
#include <vector>
#include "Array.h"
using namespace std;

class Base
{
public:
private:
	int m;
};
class Devided1:public Base
{
public:
private:
	int n;
};
class Devided2:public Base
{
public:
private:
	int x;
};
class GrandSon :public Devided1, public Devided2
{
public:
private:
	int c;
};
Array::Array()
{
	this->len = 0;
	this->space = NULL;
	cout << "Array() called" << endl;
}
Array::Array(const Array& another)
{
	if (another.len >= 0)
	{
		this->len = another.len;
		this->space = new int[this->len];
		for (int i = 0;i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}
		cout << "Array(const Array& another)...." << endl;
	}

}
Array::Array(int len)
{
	if (len < 0)
	{
		this->len = 0;
		return;
	}
	this->len = len;
	this->space = new int[this->len];
	cout << "Array::Array(int len)" << endl;
}
void Array::push_back(int value)
{

}
int Array::front()
{

}
int Array::back()
{

}
void Array::pop_back()
{

}
int Array::size()
{

}
Array::~Array()
{
	if (this->space != NULL)
	{
		delete[] this->space;
		this->space = NULL;
		len = 0;
		cout << "Array::~Array()" << endl;
	}
}

