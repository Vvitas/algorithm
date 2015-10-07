#include"../leetcodetest/head.h"

class Solution
{
public:
	vector<int> singleNumber(vector<int>& nums)
	{
		vector<int> result;
		int i, value = 0, pos = 0, val1 = 0, val2 = 0;
		for (i = 0; i < nums.size(); i++)
			value = value^nums[i];

		while (true)
		{
			if ((1 << pos)&value)
				break;
			else ++pos;
		}

		value = 1 << pos;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] & value)
				val1 = val1^nums[i];
			else val2 = val2^nums[i];
		}
		result.push_back(val1);
		result.push_back(val2);
		return result;
	}
};

int main()
{
	return 0;
}