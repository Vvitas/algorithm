#include"../leetcodetest/head.h"

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n <= 0) return 0;
		else if (1 == n) return 1;
		else if (2 == n) return 2;

		int i, temp1 = 1, temp2 = 2, result;
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