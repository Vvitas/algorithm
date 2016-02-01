class Solution(object):
    def maxSubArray(self, nums):
        currsum,maxsum = 0,''
        for num in nums:
            if currsum < 0:
                currsum = num
            else:
                currsum+=num

            if maxsum == '':
                maxsum = currsum
            elif currsum > maxsum:
                maxsum = currsum
        return maxsum