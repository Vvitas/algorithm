#include"../leetcodetest/head.h"

class Solution
{
public:
	string addBinary(string a, string b)
	{
		if (a.size() < b.size())
		{
			string temp = a;a = b;b = temp;
		}

		bool sign = false;
		int i, len1 = (int)a.size() - 1, len2 = (int)b.size() - 1;
		for (i = 0; i < b.size(); i++)
		{
			if (a[len1 - i] == '0' && b[len2 - i] == '0')
			{
				if (sign) //sign=false
				{
					a[len1 - i] = '1'; sign = false;
				}
			}
			else if ((a[len1 - i] == '0' && b[len2 - i] == '1') || (a[len1 - i] == '1' && b[len2 - i] == '0'))
			{
				if (sign) //sign=true
				{
					a[len1 - i] = '0';
				}
				else //sign=false
				{
					a[len1 - i] = '1';
				}
			}
			else
			{
				if (sign) //sign=true
				{
					a[len1 - i] = '1';
				}
				else //sign=true
				{
					a[len1 - i] = '0'; sign = true;
				}
			}
		}
		for (; i < a.size(); i++)
		{
			if (a[len1 - i] == '0')
			{
				if (sign) //sign=false
				{
					a[len1 - i] = '1'; sign = false; break;
				}
				else break; //sign=false
			}
			else
			{
				if (sign) //sign=true
				{
					a[len1 - i] = '0';
				}
				else break; //sign=false
			}
		}

		return sign ? (a = '1' + a) : a;
	}
};

int main()
{
	return 0;
}