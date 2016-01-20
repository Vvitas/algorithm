class Solution(object):
    def isPalindrome(self, s):
        news=[i.upper() for i in s if i.isalnum()]
        return news==news[::-1]


sol=Solution()
print(sol.isPalindrome("ab"))