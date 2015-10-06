#include"../leetcodetest/head.h"

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> result(rowIndex + 1, 1);

		size_t i, j;
		int temp1, temp2;
		for (i = 2; i <= rowIndex; i++)
		{
			temp1 = result[0];
			for (j = 1; j < i; j++)
			{
				temp2 = result[j];
				result[j] = temp1 + result[j];
				temp1 = temp2;
			}
		}

		return result;
	}
};

int main()
{
	return 0;
}