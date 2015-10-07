#include"../leetcodetest/head.h"

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		size_t len = 0;

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
				nums[len++] = nums[i];
		}
		return (int)len;
	}
};

int main()
{
	return 0;
}