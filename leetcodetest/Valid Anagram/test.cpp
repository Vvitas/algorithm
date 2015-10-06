#include"../leetcodetest/head.h"

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		size_t i, num[26][2] = { 0 };

		if (s.size() != t.size())
			return false;

		for (i = 0; i < s.size(); i++)
		{
			++num[s[i] - 'a'][0];
			++num[t[i] - 'a'][1];
		}

		for (i = 0; i < 26; i++)
		{
			if (num[i][0] != num[i][1])
				return false;
		}
		return true;
	}
};

int main()
{
	return 0;
}