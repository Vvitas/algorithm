#include"../leetcodetest/head.h"

class Solution //这个答案不满足时间复杂度要求,需要后续改进
{
public:
	void setZeroes(vector<vector<int>>& matrix) 
	{
		if (!matrix.size()||!matrix[0].size())
			return;

		vector<int> row(matrix.size(), false);
		vector<int> col(matrix[0].size(), false);

		size_t i, j;
		for ( i = 0; i < matrix.size(); i++)
		{
			for ( j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					row[i] = col[j] = true;
				}
			}
		}

		for (i = 0; i < matrix.size(); i++)
		{
			if (row[i])
			{
				for (j = 0; j < matrix[i].size(); j++)
				{
					matrix[i][j] = 0;
				}
			}
			else continue;
		}
		for (i = 0; i < matrix[0].size(); i++)
		{
			if (col[i])
			{
				for (j = 0; j < matrix.size(); j++)
				{
					matrix[j][i] = 0;
				}
			}
			else continue;
		}
	}
};

int main()
{
	return 0;
}