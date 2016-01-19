class NumArray(object):
    sums=[]
    def __init__(self, nums):
        if(len(nums)==0):
            return 
        temp=0
        self.sums=[]
        for i in range(len(nums)):
            temp+=nums[i]
            self.sums.append(temp)
        
    def sumRange(self, i, j):
        if j>len(self.sums) or i<0 or j<0 or  i>j:
            return 0
        if i==0:
            return self.sums[j]
        return self.sums[j]-self.sums[i-1]

nums=[-2,0,3,-5,2,-1]
num=NumArray(nums)
print(num.sumRange(2,5))
