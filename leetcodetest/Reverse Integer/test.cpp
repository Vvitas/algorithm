#include"../leetcodetest/head.h"

class Solution
{
public:
	int reverse(int x)
	{
		queue<int> data;
		bool sign = x < 0 ? true : false;

		x *= (x < 0) ? -1 : 1;
		while (x)
		{
			data.push(x % 10);
			x = x / 10;
		}

		long long result = 0;
		while (!data.empty())
		{
			result = result * 10 + data.front();
			data.pop();

			if (result > INT_MAX) return 0;
		}

		result *= sign ? -1 : 1;

		if (result<INT_MIN || result>INT_MAX)
			return 0;
		else return (int)result;
	}
};

int main()
{
	return 0;
}