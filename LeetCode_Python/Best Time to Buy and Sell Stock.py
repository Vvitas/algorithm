class Solution(object):
    def maxProfit(self, prices):
        if len(prices) <= 1:
            return 0

        low,profit = prices[0],0
        for tmp in prices:
            if low > tmp:
                low = tmp
            else:
                if (tmp - low) > profit:
                    profit = tmp - low
        return profit
