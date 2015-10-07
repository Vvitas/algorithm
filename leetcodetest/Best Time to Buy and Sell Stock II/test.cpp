#include"../leetcodetest/head.h"

class Solution 
{
public:
	int maxProfit(vector<int>& prices) 
	{
		int profit = 0;
		for (size_t i = 1; i < prices.size(); i++)
		{
			profit += (prices[i] - prices[i - 1]>0) ? (prices[i] - prices[i - 1]) : 0;
		}
		return profit;
	}
};

int main()
{
	return 0;
}