class Solution(object):
    def isPowerOfTwo(self, n):
        return n > 0 and not (n & (n - 1))
        