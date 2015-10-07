#include"../leetcodetest/head.h"

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int currsum = 0, maxsum = INT_MIN;

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (currsum < 0)
			{
				currsum = nums[i];
			}
			else currsum += nums[i];

			if (currsum > maxsum)
			{
				maxsum = currsum;
			}
		}

		return maxsum;
	}
};

int main()
{
	return 0;
}