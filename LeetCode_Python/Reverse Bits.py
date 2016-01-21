class Solution(object):
    def reverseBits(self, n):
       bit,res = 1,0
       for i in range(32):
           if bit & n:
               res+=1 << (31 - i)
           bit = bit << 1
       return res 

sol = Solution()
print(sol.reverseBits(0))