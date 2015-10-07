#include"../leetcodetest/head.h"

class Solution
{
private:
	string num2str(int num1, int num2 = 0, bool sign = true)
	{
		if (sign)
		{
			switch (num1)
			{
			case 1:return " One";
			case 2:return " Two";
			case 3:return " Three";
			case 4:return " Four";
			case 5:return " Five";
			case 6:return " Six";
			case 7:return " Seven";
			case 8:return " Eight";
			case 9:return " Nine";
			default: return "";
			}
		}
		else
		{
			if (num1 == 1)
			{
				switch (num2)
				{
				case 0:return " Ten";
				case 1:return " Eleven";
				case 2:return " Twelve";
				case 3:return " Thirteen";
				case 4:return " Fourteen";
				case 5:return " Fifteen";
				case 6:return " Sixteen";
				case 7:return " Seventeen";
				case 8:return " Eighteen";
				case 9:return " Nineteen";
				}
			}
			else
			{
				string temp = num2str(num2);
				switch (num1)
				{
				case 2:return " Twenty" + temp;
				case 3:return " Thirty" + temp;
				case 4:return " Forty" + temp;
				case 5:return " Fifty" + temp;
				case 6:return " Sixty" + temp;
				case 7:return " Seventy" + temp;
				case 8:return " Eighty" + temp;
				case 9:return " Ninety" + temp;
				}
			}
		}

	}

public:
	string numberToWords(int num)
	{
		if (0 == num) return "Zero";

		vector<int> data;
		while (num)
		{
			data.push_back(num % 1000);
			num = num / 1000;
		}

		string result;
		for (size_t i = 0; i < data.size(); i++)
		{
			string strdata;
			int temp[3] = { data[i] / 100,data[i] / 10 % 10,data[i] % 10 };

			if (temp[0] == 0 && temp[1] == 0 && temp[2] == 0) continue;

			if (temp[0] != 0)
			{
				strdata += num2str(temp[0]) + " Hundred";
			}
			if (temp[1] != 0)
			{
				strdata += num2str(temp[1], temp[2], false);
			}
			else
			{
				if (temp[2] != 0)
					strdata += num2str(temp[2]);
			}

			if (i == 3) strdata += " Billion";
			else if (i == 2) strdata += " Million";
			else if (i == 1) strdata += " Thousand";

			result = strdata + result;
		}

		return result.substr(result.find_first_not_of(' '), result.find_last_not_of(' ') + 1);
	}
};

int main()
{
	return 0;
}