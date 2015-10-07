#include"../leetcodetest/head.h"

class Solution
{
public:
	int findDuplicate(vector<int>& nums)
	{
		set<int> data;
		data.insert(nums[0]);
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (data.find(nums[i]) != data.end())
			{
				return nums[i];
			}
			else
			{
				data.insert(nums[i]);
			}
		}
	}
};

int main()
{
	return 0;
}