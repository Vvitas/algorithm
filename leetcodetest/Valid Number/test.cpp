#include"../leetcodetest/head.h"

class Solution 
{
public:
	bool isNumber(string s) 
	{
		size_t i, nume = 0, numdot = 0, numofint = 0, left = 0, right = s.length() - 1, len;
		bool signdot = false, signe = false;

		if (s.length() <= 0)
			return false;
		else //去除字符串前后空格
		{
			if (s.find_first_not_of(' ') == s.npos)
				return false;
			s = s.substr(s.find_first_not_of(' '));
			s = s.substr(0, s.find_last_not_of(' ') + 1);
		}

		//去除字符串前部符号
		if (s[0] == '+' || s[0] == '-')
		{
			if ((s = s.substr(1)).length() <= 0)
				return false;
		}

		len = s.length();
		for (i = 0; i < len; i++)
		{
			if (s[i] <= '9'&&s[i] >= '0')
				++numofint;
			else if (s[i] == '.') //小数点判别
			{
				if (signdot || signe)
					return false;
				else
				{
					if (i == len - 1 && !numofint)
						return false;
					else if ((s[i + 1] == 'e' || s[i + 1] == 'E') && !numofint)
						return false;
					signdot = true;
				}
			}
			else if (s[i] == 'e' || s[i] == 'E')
			{
				if (signe || !numofint) 
					return false;
				else
				{
					if (i == len - 1)
						return false;
					else if (s[i + 1] == '-' || s[i + 1] == '+')
					{
						if (i + 1 == len - 1)
							return false;
						else ++i;
					}
					else if (s[i + 1] < '0' || s[i + 1] > '9')
						return false;
					signe = true;
				}
			}
			else return false;
		}

		if (!numofint) 
			return false;
		else return true;
	}
};

int main()
{
	Solution test;
	cout << boolalpha << test.isNumber("46.e3") << endl;

	return 0;
}