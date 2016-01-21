class Solution(object):
    def valequal(self,x,y):
        if (x - y) < 1e-10 and (x - y) > -1e-10:
            return True
        else:
            return False 
    def pownum(self,x,n):
        if 0 == n:
            return 1.0
        elif 1 == n:
            return x
        res = self.pownum(x,n / 2)
        res*=res
        if n & 0x01:
            return res * x
        else: 
            return res
    def myPow(self, x, n):
        if self.valequal(x,0.0):
            return 0.0
        elif self.valequal(x,1.0):
            return 1.0
        elif self.valequal(x,-1.0):
            if n & 0x01:
                return -1.0
            else:
                return 1.0

        if n == 0:
            return 1.0

        if n < 0:
            return 1 / self.pownum(x,-n)
        else:
            return self.pownum(x,n)


