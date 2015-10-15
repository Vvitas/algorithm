#include"../leetcodetest/head.h"

class Solution 
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> result(2, -1);

		if (nums.size() <= 0 || target<nums[0] || target>nums[nums.size() - 1])
			return result;

		int i, left = 0, right = nums.size() - 1, mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;

			if (nums[mid] == target)
			{
				if (nums[0] == target)
					result[0] = 0;
				else
				{
					for (i = mid; i >= 0; --i)
					{
						if (nums[i] != target)
						{
							result[0] = i + 1; break;
						}
					}
				}
				if (nums[nums.size() - 1] == target)
					result[1] = nums.size() - 1;
				else
				{
					for (i = mid; i < nums.size(); i++)
					{
						if (nums[i] != target)
						{
							result[1] = i - 1; break;
						}
					}
				}
				return result;
			}
			else if (nums[mid] < target)
				left = mid + 1;
			else right = mid - 1;
		}
		return result;
	}
};

int main()
{
	int num[]{ 1 };
	vector<int> data(num, num + sizeof(num) / sizeof(int));

	Solution test;
	auto var = test.searchRange(data, 0);

	return 0;
}