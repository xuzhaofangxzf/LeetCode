#include <iostream>
class Base
{
public:
	Base()
	{
		m = 2;
	}
	int m;
};
class Devided1 :virtual public Base
{
public:
	int n;
};
class Devided2 :virtual public Base
{
public:
	int x;
};
class GrandSon :public Devided1 ,public Devided2
{
public:
private:
	int c;
};
using namespace std;
int main()
{
	GrandSon gs;
	gs.m = 100;
	return 0;
}
