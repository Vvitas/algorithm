class Solution(object):
    def maxProfit(self, prices):
        profit = 0
        for i in range(1,len(prices)):
            if prices[i] - prices[i - 1] > 0:
                profit += prices[i] - prices[i - 1]
        return profit

sol = Solution()
print(sol.maxProfit([1,2,4]))