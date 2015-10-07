#include"../leetcodetest/head.h"

class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		unsigned int i, numofcolor[3] = { 0 };

		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				++numofcolor[0];
			else if (nums[i] == 1)
				++numofcolor[1];
			else ++numofcolor[2];
		}

		for (i = 0; i < numofcolor[0]; i++)
			nums[i] = 0;
		for (; i < numofcolor[0] + numofcolor[1]; i++)
			nums[i] = 1;
		for (; i < numofcolor[0] + numofcolor[1] + numofcolor[2]; i++)
			nums[i] = 2;
	}
};

int main()
{
	return 0;
}