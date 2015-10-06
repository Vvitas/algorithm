#include"../leetcodetest/head.h"

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		if (nums.size() == 0) return false;

		unordered_set<int> data;
		data.insert(nums[0]);
		for (size_t i = 1; i < nums.size();i++)
		{
			if (data.find(nums[i]) != data.end())
				return true;
			else data.insert(nums[i]);
		}
		return false;
	}
};

int main()
{
	return 0;
}