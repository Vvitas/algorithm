#include"../leetcodetest/head.h"

class Solution 
{
public:
	int findMin(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return -1;
		else if (nums.size() == 1)
			return nums[0];

		size_t left = 0, right = nums.size() - 1, mid = 0;

		while (nums[left]>=nums[right])
		{
			if (right - left == 1)
			{
				mid = right; break;
			}

			mid = left + (right - left) / 2;
			if (nums[left] >= nums[mid])
				right = mid;
			else if (nums[right] <= nums[mid])
				left = mid;
		}
		return nums[mid];
	}
};

int main()
{
	return 0;
}