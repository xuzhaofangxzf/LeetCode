/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#if 0
#include <iostream>
#include <vector>
using namespace std;
//方法1，元素的顺序没有改变
int removeElement(vector<int>& nums, int val)
{
	int count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == val)
		{
			count++;
		}
		else
		{
			nums[i - count] = nums[i];
		}
	}
	return nums.size() - count;
}
//方法2，可以改变元素的顺序

int removeElement(vector<int>& nums, int val)
{
	int i = 0;
	int j = nums.size() - 1;
	int count = 0;
	while (i < j)
	{
		while (i < j && nums[j] == val)//找到第一个不等于val的值
		{
			j--;
			count++;
		}
		while (i < j && nums[i] != val)
		{
			i++;
		}
		if (i < j)
		{
			swap(nums[i], nums[j]);
			count++;
			i++;
			j--;
		}
	}
	//if (i == j && nums[i] == val)
	//{
	//	count++;
	//}
	return nums.size() - count;
}

int main()
{
	vector<int> ipt{ 3, 2, 2, 3 };
	int res = removeElement(ipt, 3);
	cout << res << endl;
	return 0;
}
#endif