#include"../leetcodetest/head.h"

class Solution
{
public:
	int mySqrt(int x)
	{
		if (x <= 0) return 0;

		unsigned long long left = 0, right = x, mid, val;
		while (left < right)
		{
			mid = (left + right) / 2;
			val = mid*mid;

			if (val < x)
				left = mid + 1;
			else if (val > x)
				right = mid - 1;
			else return mid;
		}

		if (left*left>x)
			return left - 1;
		else return left;

	}
};

int main()
{
	return 0;
}