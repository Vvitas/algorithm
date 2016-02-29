
#unfinished
class Solution(object):
    def findPeakElement(self, nums):
        if len(nums) == 1:
            return 0
        elif len(nums) == 2:
            return 0 if nums[0] > nums[1] else 1

        for i in range(1,len(nums) - 2):
            if nums[i] > nums[i - 1] & nums[i] > nums[i + 1]:
                return i
        return 0 if nums[0] > nums[1] else len(nums) - 1