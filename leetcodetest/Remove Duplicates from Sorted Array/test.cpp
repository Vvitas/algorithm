#include"../leetcodetest/head.h"

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (0 == nums.size()) return 0;

		size_t i, len = 0;

		for (i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[len])
			{
				nums[++len] = nums[i];
			}
		}
		return len + 1;
	}
};

int main()
{
	return 0;
}