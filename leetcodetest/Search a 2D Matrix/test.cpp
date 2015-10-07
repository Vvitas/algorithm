#include"../leetcodetest/head.h"

class Solution
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		size_t row, col;
		if (!(row = matrix.size()) || !(col = matrix[0].size()))
			return false;

		if (target<matrix[0][0] || target>matrix[row - 1][col - 1])
			return false;

		int t1 = 0, t2 = col - 1;
		while (t1 < row && t2 >= 0)
		{
			if (matrix[t1][t2] == target)
			{
				return true;
			}
			else if (matrix[t1][t2]>target)
			{
				--t2;
			}
			else ++t1;
		}

		return false;
	}
};

int main()
{
	return 0;
}