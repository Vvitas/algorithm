#include"../leetcodetest/head.h"

class Solution
{
public:
	bool wordPattern(string pattern, string str)
	{
		vector<string> strvdata;
		size_t pos1 = 0, pos2 = str.find(' ');

		while (str.npos != pos2)
		{
			strvdata.push_back(str.substr(pos1, pos2 - pos1));

			pos1 = pos2 + 1;
			pos2 = str.find(' ', pos1);
		}
		strvdata.push_back(str.substr(pos1));

		if (pattern.length() != strvdata.size())
			return false;

		map<char, string> strpattern1;
		map<char, string>::iterator itrchar;
		map<string, char> strpattern2;
		map<string, char>::iterator itrstring;
		for (size_t i = 0; i < pattern.length(); i++)
		{
			itrchar = strpattern1.find(pattern[i]);
			if (itrchar == strpattern1.end())
			{
				strpattern1.insert(make_pair(pattern[i], strvdata[i]));
			}
			else
			{
				if (itrchar->second != strvdata[i])
					return false;
			}

			itrstring = strpattern2.find(strvdata[i]);
			if (itrstring == strpattern2.end())
			{
				strpattern2.insert(make_pair(strvdata[i], pattern[i]));
			}
			else
			{
				if (itrstring->second != pattern[i])
					return false;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}