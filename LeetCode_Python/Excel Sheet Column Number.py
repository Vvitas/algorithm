class Solution(object):
    def titleToNumber(self, s):
        res = 0
        for tmp in s:
            res = res * 26 + ord(tmp) - ord('A') + 1
        return res
        