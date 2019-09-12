#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//����1�����ö��ֲ��ң��ҵ�����target��ֵ��Ȼ������������������target�����Ƚ϶��ʱ��ʱ�临�ӶȻ��һЩ
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


