#include"../leetcodetest/head.h"

class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int result = 0, tmp = n;
		while (tmp)
		{
			++result;
			tmp = tmp&(tmp - 1);
		}
		return result;
	}
};

int main()
{
	return 0;
}