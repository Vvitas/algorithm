#include"../leetcodetest/head.h"

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int i;
		bool sign = true;
		vector<int> result(digits.begin(), digits.end());

		for (i = result.size() - 1; i >= 0; i--)
		{
			if (result[i] == 9)
			{
				result[i] = 0;
			}
			else
			{
				result[i] += 1; sign = false;
			}
			if (!sign) break;
		}

		if (sign && i < 0)
			result.insert(result.begin(), 1);
		return result;
	}
};

int main()
{
	return 0;
}