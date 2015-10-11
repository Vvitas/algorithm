#include"../leetcodetest/head.h"

//此题初始想复杂了,竟想通过头尾相减解决
class Solution 
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() <= 1)
			return 0;

		int low = prices[0], profit = 0, temp;
		for (size_t i = 1; i < prices.size(); i++)
		{
			if (low > prices[i])
				low = prices[i];
			else
			{
				profit = ((temp = prices[i] - low) > profit) ? temp : profit;
			}
		}
		return profit;
	}
};

int main()
{
	int num[]{ 2,1,2,1,0,0,1 };
	vector<int> data(num, num + sizeof(num) / sizeof(int));
	Solution test;
	test.maxProfit(data);

	return 0;
}