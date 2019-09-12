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
			if (nums[i] > nums[i - 1])//�ҵ���һ��ǰ��С�ں������
			{
				int j = size - 1;
				//�ҵ�i�����[i - 1]�����С����

				while (j >= i)
				{
					if (nums[i - 1] >= nums[j])
					{
						j--;
					}
					else
					{
						//�ҵ��˱�nums[i - 1]��ĵ�һ����
						break;
					}
				}
				swap(nums[i - 1], nums[j]);

				//��ʣ�µİ���������
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
		//�����ǴӴ�С�������
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