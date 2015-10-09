#include"../leetcodetest/head.h"

class Solution 
{
public:
	bool isNumber(string s) 
	{
		size_t i, nume = 0, numofgdigit = 0;
		bool signdot = false, signe = false;

		if (s.length() <= 0) //去除字符串前后部分的空格
			return false;
		else
		{
			for (i = 0; i < s.length(); i++)
			{
				if (s[i] != ' ')
				{
					if (s[i] > '9' || s[i] < '0')
					{
						if (s[i] != '.' && s[i] != 'e' && s[i] != 'E' && s[i] != '-' && s[i] != '+')
							return false;
					}
					else break;
				}
			}
			if (i == s.length()) 
				return false;
			s = s.substr(s.find_first_not_of(' '));
			if (s.length() <= 0) 
				return false;
			s = s.substr(0, s.find_last_not_of(' ') + 1);
			if (s.length() <= 0)
				return false;
		}	

		if (s.length() <= 0) 
			return false;
		else if (s[0] == '-' || s[0] == '+')
		{
			if ((s = s.substr(1)).length() <= 0)
				return false;
		}

		for (i = 0; i < s.length(); i++)
		{
			if (s[i] <= '9' && s[i] >= '0')
			{
				++numofgdigit;
			}
			else if (s[i] == '.')
			{
				if (signdot || signe)
					return false;
				else 
				{
					if (!numofgdigit)
					{
						if (i == s.length() - 1)
						{
							return false;
						}
						else
						{
							if (s[i + 1] == 'e' || s[i + 1] == 'E')
								return false; 
						}
					}
					signe = true;
				}	
			}
			else if (s[i] == 'E' || s[i] == 'e')
			{
				if (signdot || !numofgdigit)
					return false;
				else
				{
					
					if (i != s.length() - 1)
					{
						if (s[i + 1] == '-' || s[i + 1] == '+')
						{
							if (i + 1 == s.length() - 1)
								return false;
							else ++i;
						}
						else if (s[i + 1] > '9' || s[i + 1] < '0')
							return false;
					}
					else return false;
					signdot = true;
				}
			}
			else return false;
		}
		if (!numofgdigit) 
			return false;
		else return true;
	}
};

int main()
{
	Solution test;
	cout << boolalpha << test.isNumber("+.8") << endl;

	return 0;
}