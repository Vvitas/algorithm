class Solution(object):
    def SubisIsomorphic(self,s,t):
        res={}
        for i in range(len(s)):
            if s[i] not in res:
                res[s[i]]=t[i]
            elif res[s[i]]!=t[i]:
                return False
        return True
    def isIsomorphic(self, s, t):
        if len(s)!=len(t):
            return False
        return self.SubisIsomorphic(s,t) and self.SubisIsomorphic(t,s)

sol=Solution()
print(sol.isIsomorphic("ab","aa"))
print(sol.isIsomorphic("abcccc","aaeeee")) 