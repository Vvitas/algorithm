#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

class Solution {
public:
	string removeDuplicateLetters(string s)
	{
		string res = "0";
		int letters[256] = { 0 };
		bool visited[256] = { false };

		for (auto& tmp : s) ++letters[tmp];
		for (auto& tmp : s)
		{
			--letters[tmp];
			if (visited[tmp]) continue;
			while (tmp < res.back() && letters[res.back()])
			{
				visited[res.back()] = false;
				res.pop_back();
			}
			res += tmp;
			visited[tmp] = true;
		}

		return res.substr(1);
	}
};

int main()
{
	Solution test;
	cout << test.removeDuplicateLetters("bcabc") << endl;
	cout << test.removeDuplicateLetters("cbacdcbc") << endl;
	return 0;
}