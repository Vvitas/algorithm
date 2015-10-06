#include"../leetcodetest/head.h"

class Solution 
{
private:
	//int转string的简单做法,后续可以多多采用
	string format(int begin, int end)
	{
		char buffer[32] = { 0 };
		if (end == begin)
		{
			sprintf(buffer, "%d", begin);
		}
		else
		{
			sprintf(buffer, "%d->%d", begin, end);
		}
		return string(buffer);
	}

public:
	vector<string> summaryRanges(vector<int>& nums) 
	{
		vector<string> result;
		if (nums.size() < 1) return result;

		int left = nums[0], right = nums[0];
		for (size_t i = 1; i < nums.size(); i++)
		{
			if (nums[i] == right || nums[i] == right + 1)
			{
				right = nums[i];
			}
			else
			{
				result.push_back(format(left, right));
				left = right = nums[i];
			}
		}
		result.push_back(format(left, right));
		return result;
	}
};

int main()
{
	return 0;
}