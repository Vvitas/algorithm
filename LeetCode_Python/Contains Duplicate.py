class Solution(object):
    def containsDuplicate(self, nums):
        if len(nums) <= 1:
            return False
        data = set()
        for tmp in nums:
            if tmp in data:
                return True
            else:
                data.add(tmp)
        return False
