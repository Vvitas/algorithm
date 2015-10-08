#include"../leetcodetest/head.h"

class Solution
{
private:
	void swap(int& a, int& b)
	{
		int t = a;a = b;b = t;
	}

	bool isSwap(vector<int>& data, int left, int right)
	{
		if (left > right) return false;
		for (int i = left; i < right; i++)
		{
			if (data[i] == data[right])
				return false;
		}
		return true;
	}

	void PermutionData(vector<int>& data, int k, int m, vector<vector<int>>& result)
	{
		if (k == m)
		{
			result.push_back(data); return;
		}

		for (int i = k; i <= m; i++)
		{
			if (isSwap(data, k, i))
			{
				swap(data[i], data[k]);
				PermutionData(data, k + 1, m, result);
				swap(data[i], data[k]);
			}
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> result;
		PermutionData(nums, 0, nums.size() - 1, result);
		return result;
	}
};


int main()
{
	return 0;
}