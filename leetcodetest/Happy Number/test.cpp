#include"../leetcodetest/head.h"

class Solution
{
public:
	bool isHappy(int n)
	{
		if (n < 1) return false;
		else if (1 == n) return true;

		unordered_set<int> data;
		data.insert(n);

		while (true)
		{
			int sum = 0;
			while (n)
			{
				sum += (n % 10)*(n % 10);
				n = n / 10;
			}

			if (1 == sum)
				return true;
			else if (data.find(sum) != data.end())
				return false;

			data.insert(n = sum);
		}
	}
};

int main()
{
	return 0;
}