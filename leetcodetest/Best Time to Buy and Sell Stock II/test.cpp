#include"../leetcodetest/head.h"

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int tmp, profit = 0;
		for (size_t i = 1; i < prices.size(); i++)
		{
			if ((tmp = prices[i] - prices[i - 1])>0)
				profit += tmp;
		}
		return profit;
	}
};

int main()
{
	return 0;
}