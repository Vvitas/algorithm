class Solution(object):
    def isPowerOfThree(self, n):
        if n<=0 or not (n%2):
            return False
        num1,num2=1,3
        while True:
            if num1==n or num2==n:
                return True
            elif n>num2:
                num1,num2=num2,num2*3
            else:
                return False