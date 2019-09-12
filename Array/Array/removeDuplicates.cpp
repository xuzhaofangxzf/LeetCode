// Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) 
	{
		if (nums.size() == 0)
		{
			return 0;
		}
		int k = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[i - 1])
			{
				nums[k++] = nums[i];
			}
		}
		return k;
	}
};
