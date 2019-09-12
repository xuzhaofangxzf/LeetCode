#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int size = nums.size();
		if (nums.size() <= 0)
		{
			return;
		}
		int i;
		for (i = size - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])//找到第一个前面小于后面的数
			{
				int j = size - 1;
				//找到i后面比[i - 1]大的最小的数

				while (j >= i)
				{
					if (nums[i - 1] >= nums[j])
					{
						j--;
					}
					else
					{
						//找到了比nums[i - 1]大的第一个数
						break;
					}
				}
				swap(nums[i - 1], nums[j]);

				//将剩下的按升序排列
				reverse(nums.begin() + i, nums.end());
#if 0
				int k = size - 1;
				while (i < k)
				{
					swap(nums[i], nums[k]);
					i++;
					k--;
				}
#endif
				return;
			}
		}
#if 0
		//数组是从大到小，有序的
		i = 0;
		int j = size - 1;
		while (i < j)
		{
			swap(nums[i], nums[j]);
			i++;
			j--;
		}
#endif
		reverse(nums.begin(), nums.end());
	}



	//void nextPermutation(vector<int>& nums)
	//{
	//	int size = nums.size();
	//	if (nums.size() <= 1)
	//	{
	//		return;
	//	}
	//	vector<int>::iterator it;
	//	for (it = nums.end(); it != nums.begin() + 1; it--)
	//	{
	//		if (*it > *(it - 1))
	//		{
	//			break;
	//		}
	//	}
	//	if(it)
	//	vector<int>::iterator it2 = upper_bound(it, nums.end(), *(it - 1));
	//	swap(*it2, *(it - 1));
	//	
	//}
};