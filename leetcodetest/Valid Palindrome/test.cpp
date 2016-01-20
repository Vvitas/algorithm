#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {

		if (s.length() <= 1) return true;

		int i = 0, j = (int)s.length() - 1;
		while (i < j)
		{
			for (;i < j;++i)
			{
				if (isalnum(s[i]))
				{
					s[i] = toupper(s[i]); break;
				}
			}
			for (;j > i;--j)
			{
				if (isalnum(s[j]))
				{
					s[j] = toupper(s[j]); break;
				}
			}
			if (s[i] != s[j]) return false;
			++i;--j;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	cout << boolalpha << sol.isPalindrome("a.") << endl;
	return 0;
}