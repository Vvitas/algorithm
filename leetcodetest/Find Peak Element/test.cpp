#include"../leetcodetest/head.h"

class Solution
{
public:
	int findPeakElement(vector<int>& nums)
	{
		if (nums.size() == 1) return 0;
		else if (nums.size() == 2)
		{
			return nums[0] > nums[1] ? 0 : 1;
		}

		for (size_t i = 1; i < nums.size() - 1; i++)
		{
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
			{
				return i;
			}
		}
		if (nums[0] > nums[1]) return 0;else return nums.size() - 1;
	}
};

int main()
{
	return 0;
}