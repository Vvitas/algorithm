#include"../leetcodetest/head.h"

class Solution
{
private:
	string AddNum(string s1, string s2)
	{
		if (s1.length() == 0 || s1 == "0")
			return s2;
		if (s2.length() == 0 || s2 == "0")
			return s1;

		if (s1.length() < s2.length())
		{
			string temp = s1; s1 = s2; s2 = temp;
		}

		int i, j, t1 = 0, t2 = 0;
		bool sign = false;
		for (i = s1.length() - 1, j = s2.length() - 1; i >= 0 && j >= 0; --i, --j)
		{
			t1 = s1[i] - '0' + s2[j] - '0' + t2;
			t2 = t1 / 10;
			s1[i] = t1 % 10 + '0';
		}
		for (; i >= 0 && t2 != 0; --i)
		{
			t1 = s1[i] - '0' + t2;
			t2 = t1 / 10;
			s1[i] = t1 % 10 + '0';
		}
		if (t2 != 0)
			s1.insert(s1.begin(), t2 + '0');

		return s1;
	}

public:
	string multiply(string num1, string num2)
	{
		num1 = num1.substr(num1.find_first_not_of(' '));
		num2 = num2.substr(num2.find_first_not_of(' '));

		if (num1.length() == 0 || num2.length() == 0)
			return "0";
		if (num1 == "0" || num2 == "0")
			return "0";

		if (num1.length() < num2.length())
		{
			string temp = num1; num1 = num2; num2 = temp;
		}

		int i, j, t1 = 0, t2 = 0;
		vector<string> addnum;
		for (i = num2.length() - 1; i >= 0; --i)
		{
			string tstr = num1;
			for (j = num2.length() - 1 - i; j > 0; j--)
				tstr.append("0");

			if (num2[i] == '0')
			{
				addnum.push_back("0"); continue;
			}
			else if (num2[i] == '1')
			{
				addnum.push_back(tstr); continue;
			}

			for (j = tstr.length() - 1; j >= 0; --j)
			{
				t1 = (tstr[j] - '0')*(num2[i] - '0') + t2;
				t2 = t1 / 10;
				tstr[j] = t1 % 10 + '0';
			}

			if (t2 != 0)
				tstr.insert(tstr.begin(), t2 + '0');
			t1 = t2 = 0;
			addnum.push_back(tstr);
		}

		string result;
		for (size_t i = 0; i < addnum.size(); i++)
		{
			result = AddNum(addnum[i], result);
		}
		return result;
	}
};

int main()
{
	Solution test;
	cout << test.multiply("42", "10") << "==" << 54321 * 980 << endl;

	return 0;
}