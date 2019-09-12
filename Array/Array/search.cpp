#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
#if 0
			//不要以左侧进行比较，当数组长度为2的时候，l == mid，此时会漏掉这个情况的判断
			if (nums[l] < nums[mid])
			{
				if(target < nums[mid] && target >= nums[l])
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}
			else if(nums[l] == nums[mid])
			{
				l = mid + 1;

			}
			else
			{
				if (target > nums[mid] && target <= nums[r])
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
#endif
			if (nums[r] > nums[mid])
			{
				if (target > nums[mid] && target < nums[r])
				{
					l = l + 1;
				}
				else if (target == nums[r])
				{
					return r;
				}
				else
				{
					r = mid - 1;
				}
			}
			else
			{
				if (target < nums[mid] && target > nums[l])
				{
					r = mid - 1;
				}
				else if (target == nums[l])
				{
					return l;
				}
				else
				{
					l = mid + 1;
				}
			}
		}
		return -1;
	}
};
int main()
{
	Solution s1;
	vector<int> input{ 3, 1 };
	s1.search(input, 1);
}