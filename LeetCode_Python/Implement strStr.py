class Solution(object):
    def strStr(self, haystack, needle):
        len1,len2 = len(haystack),len(needle)
        if len2 <= 0:
            return 0
        if len1 <= 0 or len1 < len2:
            return -1
        for i in range(0,len1 - len2 + 1):
            if haystack[i:i + len2] == needle:
                return i
        return -1

sol = Solution()
sol.strStr('a','a')
        