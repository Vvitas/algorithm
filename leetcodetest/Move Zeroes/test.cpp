#include"../leetcodetest/head.h"

class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		size_t i = 0, len = 0;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i])
				nums[len++] = nums[i];
		}
		for (i = len; i < nums.size(); i++)
			nums[i] = 0;
	}
};

int main()
{
	return 0;
}