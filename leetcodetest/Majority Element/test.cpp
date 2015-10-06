#include"../leetcodetest/head.h"

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int i, result = nums[0], frq = 1;
		for (i = 1; i < nums.size(); i++)
		{
			if (frq == 0)
			{
				result = nums[i], frq = 1;
			}
			else if (nums[i] == result)
				++frq;
			else --frq;

			if (frq > nums.size() / 2) return result;
		}
		return result;
	}
};

int main()
{
	return 0;
}