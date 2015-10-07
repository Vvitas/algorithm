#include"../leetcodetest/head.h"

struct setcmp
{
	bool operator()(const int& a, const int& b)
	{
		return a > b;
	}
};

class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		multiset<int, setcmp> intSet;
		multiset<int, setcmp>::iterator itr;

		k = nums.size() - k + 1;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (intSet.size() < k)
				intSet.insert(nums[i]);
			else
			{
				if (nums[i] < *intSet.begin())
				{
					intSet.erase(intSet.begin());
					intSet.insert(nums[i]);
				}
			}
		}
		return *intSet.begin();
	}
};

int main()
{
	return 0;
}

