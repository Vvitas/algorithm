#include"../leetcodetest/head.h"

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		char data[1000000] = { 0 };
		size_t i, len = nums.size();

		for (i = 0; i < len; i++)
			data[nums[i]] = 1;
		for (i = 0; i < len + 1; i++)
			if (!data[i]) return i;

		return 0;
	}
};

int main()
{
	return 0;
}