#include <iostream>
using namespace std;
class MyClass
{
public:
	MyClass(int a, int b):m_a(a), m_b(b)
	{

	}
	int PrintClass(int c, int d = MyClass(10, 20).m_b)
	{
		cout << "c: " << c << " d:" << d << endl;
		return 0;
	}
	~MyClass()
	{

	}
private:
	int m_a;
	int m_b;
};
class myclass
{

	static int m_a;
public:
	int get()
	{
		return m_a;
	}
};
int myclass::m_a = 0;
int main()
{
	MyClass myclass(10, 390);
	myclass.PrintClass(20);
	return 0;
}
