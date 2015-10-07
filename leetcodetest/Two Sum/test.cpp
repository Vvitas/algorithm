#include"../leetcodetest/head.h"

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{

		vector<int> result, vtdata(nums.begin(), nums.end());
		if (nums.size() <= 1) return result;
		sort(vtdata.begin(), vtdata.end());

		bool sign = false, find[2] = { false };
		int left = 0, right = nums.size() - 1, sum;
		while (left < right)
		{
			sum = vtdata[left] + vtdata[right];

			if (sum == target)
			{
				sign = true; break;
			}
			else if (sum < target)
				++left;
			else
				--right;
		}

		if (sign)
		{
			for (size_t i = 0; i < nums.size(); i++)
			{
				if (nums[i] == vtdata[left])
				{
					find[0] = true;
					result.push_back(i + 1);

					if (find[0] && find[1])
						break;
				}
				else if (nums[i] == vtdata[right])
				{
					find[1] = true;
					result.push_back(i + 1);

					if (find[0] && find[1])
						break;
				}
			}
		}

		return result;
	}
};

int main()
{
	return 0;
}