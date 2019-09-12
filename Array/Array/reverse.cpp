#include <iostream>
using namespace std;

int reverse(int x)
{
	int res = 0;
	while (x != 0)
	{
		if (res > INT_MAX / 10)
		{
			return 0;
		}
		if (res < INT_MIN / 10)
		{
			return 0;
		}
		res = res * 10;
		int mod = x % 10;
		x = x / 10;
		if (mod > 0 && res > INT_MAX - mod) //最大溢出
		{
			return 0;
		}
		if (mod < 0 && res < INT_MIN - mod) //最小溢出
		{
			return 0;
		}
		res += mod;
	}
	return res;
}
