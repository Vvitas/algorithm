class Solution(object):
    def majorityElement(self, nums):
        res,frq = 0,0
        for data in nums:
            if frq == 0:
                res = data
                frq = 1
            elif data == res:
                frq = frq + 1
            else:
                frq = frq - 1
            if frq > len(nums) / 2:
                return res
        return res

sol = Solution()
sol.majorityElement([3,3,4])