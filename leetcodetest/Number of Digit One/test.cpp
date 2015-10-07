#include"../leetcodetest/head.h"

class Solution 
{
public:
	int countDigitOne(int n) 
	{
		if (n <= 0) return 0;

		int res = 0;
		for (long m = 1; m <= n; m = m * 10)
		{
			int a = n / m, b = n % m;
			res += (a + 8) / 10 * m + (a % 10 == 1)*(b + 1);
		}
		return res;
	}
};

int main()
{
	return 0;
}