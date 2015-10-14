#include"../leetcodetest/head.h"

//此题不易直接解决,故两步走,先寻找最小的数
//将数组分为两部分,确定范围使用二分查找
class Solution 
{
private:
	int findTarget(vector<int>& nums, size_t left, size_t right, int target)
	{
		if (target<nums[left] || target>nums[right])
			return -1;

		size_t mid;
		while (left<=right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return (int)mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else if (nums[mid] > target)
				right = mid - 1;
		}
		return -1;
	}

public:
	int search(vector<int>& nums, int target) 
	{
		size_t len = nums.size();
		if (len == 0)
			return -1;
		else if (len == 1)
		{
			if (nums[0] == target)
				return 0;
			else return -1;
		}

		//mid必须初始化,以避免初始元素即为最小元素现象
		size_t left = 0, right = len - 1, mid = left;

		//寻找旋转数组中最小的数字
		while (nums[left] >= nums[right]) 
		{
			if (right - left == 1)
			{
				mid = right; break;
			}

			mid = left + (right - left) / 2;
			if (nums[mid] >= nums[left])
				left = mid;
			else if (nums[mid] <= nums[right])
				right = mid;
		}

		if (mid == 0)
			return findTarget(nums, 0, len - 1, target);
		else
		{
			if (nums[0] <= target && nums[mid - 1] >= target)
				return findTarget(nums, 0, mid - 1, target);
			else if (nums[mid] <= target && nums[len - 1] >= target)
				return findTarget(nums, mid, len - 1, target);
		}

		return -1;
	}
};

int main()
{
	int num[]{ 1,3 };
	vector<int> data(num, num + sizeof(num) / sizeof(int));
	Solution test;
	cout << test.search(data, 0) << endl;

	return 0;
}