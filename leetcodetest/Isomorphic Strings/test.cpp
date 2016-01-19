#include <map>
using std::map;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
	bool isIsomorphic(string s, string t) {

		if (s.length() != t.length())
			return false;
		if (s.empty())
			return true;

		map<char, char> strmap1,strmap2;

		for (size_t i = 0;i < s.length();++i)
		{
			auto res = strmap1.find(s[i]);

			if (res == strmap1.end())
			{
				strmap1.insert(map<char, char>::value_type(s[i], t[i]));
			}
			else
			{
				if (t[i] != res->second) return false;
			}
		}
		for (size_t i = 0;i < s.length();++i)
		{
			auto res = strmap2.find(t[i]);

			if (res == strmap2.end())
			{
				strmap2.insert(map<char, char>::value_type(t[i], s[i]));
			}
			else
			{
				if (s[i] != res->second) return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution test;
	cout << std::boolalpha << test.isIsomorphic("ab", "aa") << endl;
	cout << std::boolalpha << test.isIsomorphic("foo", "bar") << endl;
	return 0;
}