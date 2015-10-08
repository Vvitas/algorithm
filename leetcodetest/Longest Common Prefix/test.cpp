#include"../leetcodetest/head.h"

class Solution 
{
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		if (strs.size() <= 0) return "";
		else if (strs.size() == 1) return strs[0];

		size_t i, j, len;
		string result = strs[0];
		for (i = 1; i < strs.size(); ++i)
		{
			len = (result.size() < strs[i].size()) ? result.size() : strs[0].size();
			if (0 == len) return "";

			for (j = 0; j < len; ++j)
			{
				if (result[j] != strs[i][j])
					break;
			}

			result = result.substr(0, j);
		}
		return result;
	}
};

int main()
{
	return 0;
}