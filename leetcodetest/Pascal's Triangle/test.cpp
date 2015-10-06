#include"../leetcodetest/head.h"

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> result;

		if (numRows >= 1)
		{
			vector<int> data(1, 1);
			result.push_back(data);
		}
		if (numRows >= 2)
		{
			vector<int> data(2, 1);
			result.push_back(data);
		}

		for (size_t i = 2; i < numRows; i++)
		{
			vector<int> data(i + 1, 0);
			data[0] = data[i] = 1;

			for (size_t j = 1; j < i; j++)
			{
				data[j] = result[i - 1][j - 1] + result[i - 1][j];
			}

			result.push_back(data);
		}

		return result;
	}
};

int main()
{
	return 0;
}