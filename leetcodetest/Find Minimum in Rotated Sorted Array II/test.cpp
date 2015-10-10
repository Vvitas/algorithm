#include"../leetcodetest/head.h"

class Solution
{
private:
	int FindInOrder(vector<int>& data, size_t left, size_t right)
	{
		int min = data[left];
		for (size_t i = left + 1; i <= right; i++)
		{
			if (min > data[i]) min = data[i];
		}
		return min;
	}

public:
	int findMin(vector<int>& nums)
	{
		if (nums.size() == 0)
			return -1;
		else if (nums.size() == 1)
			return nums[0];

		size_t left = 0, right = nums.size() - 1, mid = 0;

		while (nums[left] >= nums[right])
		{
			if (right - left == 1)
			{
				mid = right; break;
			}

			mid = left + (right - left) / 2;

			if (nums[left] == nums[mid] && nums[right] == nums[mid])
				return FindInOrder(nums, left, right);

			if (nums[left] <= nums[mid])
				left = mid;
			else if (nums[right] >= nums[mid])
				right = mid;
		}
		return nums[mid];
	}
};

int main()
{
	int num[]{ 1,1,3,1 };
	vector<int> data(num, num + sizeof(num) / sizeof(int));
	Solution test;
	test.findMin(data);

	return 0;
}