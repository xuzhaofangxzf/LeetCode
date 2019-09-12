#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//方法1：先用二分查找，找到等于target的值，然后左右线性搜索，在target个数比较多的时候，时间复杂度会高一些
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		int left = 0;
		int right = nums.size() - 1;
		vector<int> res = { -1, -1 };
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (target == nums[mid])
			{
				int i = mid, j = mid;
				while (nums[i] == nums[mid])
				{
					i--;
					if (i < 0)
					{
						break;
					}
				}
				while (nums[j] == nums[mid])
				{
					j++;
					if (j > nums.size() - 1)
					{
						break;
					}
				}
				res[0] = i + 1;
				res[1] = j - 1;

				return res;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return res;
	}
};


