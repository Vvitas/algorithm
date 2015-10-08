#include"../leetcodetest/head.h"

class Solution 
{
public:
	int strStr(string haystack, string needle) 
	{
		if (needle.size() <= 0)
			return 0;
		else if (haystack.size() <= 0 || haystack.size() < needle.size())
			return -1;
		else 
		{
			size_t len1 = haystack.length(), len2 = needle.length();
			for (size_t i = 0; i <= len1 - len2; i++)
			{
				if (haystack.substr(i, len2) == needle)
					return i;
			}
			return -1;
		}
	}
};

int main()
{
	Solution test;
	test.strStr("a", "a");
	return 0;
}