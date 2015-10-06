#include"../leetcodetest/head.h"

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int i, len = 0, right = s.size() - 1;

		if (' ' == s[right])
		{
			while (right >= 0 && s[right] == ' ')
			{
				--right;
			}
		}
		if (right < 0) return 0;

		for (i = right; i >= 0; i--)
		{
			if (' ' != s[i])
			{
				++len;
			}
			else break;
		}
		return len;
	}
};

int main()
{
	return 0;
}