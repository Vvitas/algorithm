#include"../leetcodetest/head.h"

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int left = 0, right = (int)nums.size() - 1, mid, length = nums.size();

		while (left <= right)
		{
			mid = left + (right - left) / 2;

			if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				right = mid - 1;
			else left = mid + 1;
		}
		return left;
	}
};

int main()
{
	return 0;
}