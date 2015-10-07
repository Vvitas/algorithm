#include"../leetcodetest/head.h"

class Solution
{
public:
	int myAtoi(string str)
	{
		bool sign = false;
		long long result = 0;
		size_t i, length = str.length();

		if (length <= 0) return 0;
		str = str.substr(str.find_first_not_of(' '));
		if (str.length() <= 0) return 0;

		if (str[0] == '+') str = str.substr(1);
		else if (str[0] == '-')
		{
			sign = true;str = str.substr(1);
		}
		else if (str[0] > '9'&&str[0] < '0') return 0;

		for (i = 0; i < str.length(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				result = result * 10 + str[i] - '0';

				if (result > INT_MAX) break;
			}
			else break;
		}

		if (sign == true)
			result *= -1;

		if (result > INT_MAX) return INT_MAX;
		else if (result < INT_MIN) return INT_MIN;
		else return (int)result;
	}
};

int main()
{
	return 0;
}