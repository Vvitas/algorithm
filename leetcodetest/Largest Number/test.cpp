#include"../leetcodetest/head.h"

bool cmp(const string& a, const string& b)
{
	return (a + b) > (b + a);
}

string num2str(int num)
{
	if (0 == num)
		return "0";

	string result;
	while (num)
	{
		result += num % 10 + '0';
		num /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

class Solution
{
public:
	string largestNumber(vector<int>& nums)
	{
		size_t i, len = nums.size();

		string result;
		vector<string> vtdata;
		vtdata.reserve(len);

		for (i = 0; i < len; ++i)
		{
			vtdata.push_back(num2str(nums[i]));
		}
		sort(vtdata.begin(), vtdata.end(), cmp);
		for (i = 0; i < len; i++)
		{
			result += vtdata[i];
		}

		if (result.find_first_not_of('0') == result.npos)
			return "0";
		else return result;
	}
};

int main()
{
	return 0;
}