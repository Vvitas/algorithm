#include"../leetcodetest/head.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
	int firstBadVersion(int n)
	{
		if (n <= 0) return 0;
		if (isBadVersion(1)) return 1;
		if (isBadVersion(n) && (!isBadVersion(n - 1))) return n;

		bool sign = false;
		int left = 1, right = n, mid;

		while (left <= right)
		{
			mid = left + (right - left) / 2;
			sign = isBadVersion(mid);

			if (sign)
			{
				if (isBadVersion(mid - 1))
					right = mid - 1;
				else return mid;
			}
			else
			{
				if (isBadVersion(mid + 1))
					return mid + 1;
				else left = mid + 1;
			}
		}
		return 0;
	}
};

int main()
{
	return 0;
}