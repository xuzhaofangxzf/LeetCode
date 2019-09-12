#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#if 0
//方法1，暴力解法
int maxArea(vector<int>& height)
{
	if (height.size() <= 1)
	{
		return 0;
	}
	int maxArea = min(height[0], height[1]);//选取第一个为最大面积
	for (int i = 0; i < height.size() - 1; i++)
	{
		for (int j = i + 1; j < height.size(); j++)
		{
			if (min(height[j], height[i]) * (j - i) > maxArea)
			{
				maxArea = min(height[j], height[i]) * (j - i);
			}
		}
	}
	return maxArea;
}
#endif
//2，双指针方法
int maxArea(vector<int>& height)
{
	if (height.size() <= 1)
	{
		return 0;
	}
	int i = 0;
	int j = height.size() - 1;
	int maxArea = min(height[0], height[height.size() - 1]) * (height.size() - 1);//选取第一组为最大面积

	while (i < j)
	{
		if (height[i] < height[j])
		{
			maxArea = max(maxArea, height[i] * (j - i));
			i++;
		}
		else
		{
			maxArea = max(maxArea, height[j] * (j - i));
			j--;
		}
	}
	return maxArea;

}