#include"../leetcodetest/head.h"

class Solution //不够简洁,待后续优化
{
private:
	int Str2Num(string str)
	{
		if (str.length() == 0 || str == "0")
			return 0;

		int result = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			result = result * 10 + str[i] - '0';
		}
		return result;
	}

public:
	int compareVersion(string version1, string version2) 
	{
		string temp;
		size_t i, pos;
		vector<int> cmp1, cmp2;
		
		while (true)
		{
			if ((pos = version1.find('.')) == version1.npos)
			{
				cmp1.push_back(Str2Num(version1));
				break;
			}
			else
			{
				cmp1.push_back(Str2Num(version1.substr(0, pos)));
				version1 = version1.substr(pos + 1, version1.length() - pos);
			}
		}
		while (true)
		{
			if ((pos = version2.find('.')) == version2.npos)
			{
				cmp2.push_back(Str2Num(version2));
				break;
			}
			else
			{
				cmp2.push_back(Str2Num(version2.substr(0, pos)));
				version2 = version2.substr(pos + 1, version2.length() - pos);
			}
		}

		for (i = 0; i < cmp1.size() && i < cmp2.size(); i++)
		{
			if (cmp1[i] == cmp2[i])
				continue;
			else if (cmp1[i] > cmp2[i])
				return 1;
			else return -1;
		}
		if (i == cmp1.size() && i == cmp2.size())
			return 0;
		else
		{
			if (i < cmp1.size())
			{
				for (; i < cmp1.size(); i++)
				{
					if (cmp1[i] != 0)
						return 1;
				}
				return 0;
			}
			else
			{
				for (; i < cmp2.size(); i++)
				{
					if (cmp2[i] != 0)
						return -1;
				}
				return 0;
			}
		}
	}
};

int main()
{
	Solution test;
	cout << test.compareVersion("111.112.113.114", "111.2222") << endl;

	return 0;
}