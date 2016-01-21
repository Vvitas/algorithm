class Solution(object):
    def climbStairs(self, n):
        if n < 0:
            return 0
        elif n <= 2:
            return n

        t1,t2,res = 1,2,0
        for i in range(2,n - 1):
            res = t1 + t2
            t1 = t2
            t2 = res
        return res 


        