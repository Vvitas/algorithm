#include"../leetcodetest/head.h"

//参照网上答案解决的,后续需自己再想想
class Solution 
{
public:
	int singleNumber(vector<int>& nums)
	{
		int i, j, bit[32] = { 0 }, len = (int)nums.size(), result = 0;


		for (i = 0; i < 32; i++)
		{
			for ( j = 0; j < len; j++)
			{
				bit[i] += (nums[j] >> i) & 1;
			}
			result |= (bit[i] % 3) << i;
		}

		return result;
	}
};

int main()
{
	return 0;
}