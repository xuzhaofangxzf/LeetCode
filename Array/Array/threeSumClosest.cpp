#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> nums, int target)
{
	if (nums.size() < 3)
	{
		return 0;
	}
	int res = nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	int j, k;
	int sums;
	for (int i = 0; i < nums.size() - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		j = i + 1;
		k = nums.size() - 1;
		while (j < k)
		{
			sums = nums[i] + nums[j] + nums[k];
			if (sums == target)
			{
				return sums;
			}
			else if (sums < target)
			{
				res = abs(sums - target) < abs(res - target) ? sums : res;
				j++;
			}
			else
			{
				res = abs(sums - target) < abs(res - target) ? sums : res;
				k--;
			}
			
		}
	}
	return res;
}


//int main()
//{
//	vector<int> ipt{ 1,2,4,8,16,32,64,128 };
//	int res = threeSumClosest(ipt, 82);
//	cout << res << endl;
//	return 0;
//}