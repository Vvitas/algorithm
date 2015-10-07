#include"../leetcodetest/head.h"

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int res = 0;
		for (size_t i = 0; i < nums.size(); ++i)
			res = res^nums[i];
		return res;
	}
};

int main()
{
	return 0;
}