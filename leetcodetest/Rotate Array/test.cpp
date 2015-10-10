#include"../leetcodetest/head.h"

class Solution 
{
public:
	void rotate(vector<int>& nums, int k) 
	{
		size_t len = nums.size();

		if (0 == k || 0 == len) 
			return;
		else k = k % nums.size();

		reverse(nums.begin(), nums.begin() + len - k);
		reverse(nums.begin() + len - k , nums.end());
		reverse(nums.begin(), nums.end());
	}
};

int main()
{
	int num[]{ 1,2,3,4,5,6,7,8,9 };
	vector<int> data(num, num + sizeof(num) / sizeof(int));
	Solution test;
	test.rotate(data, 3);
	return 0;
}