#include"../leetcodetest/head.h"

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n < 0) return 0;
		else if (n <= 2) return n;

		size_t i, temp1 = 1, temp2 = 2, result;
		for (i = 2; i < n; i++)
		{
			result = temp1 + temp2;
			temp1 = temp2;
			temp2 = result;
		}

		return result;
	}
};

int main()
{
	return 0;
}