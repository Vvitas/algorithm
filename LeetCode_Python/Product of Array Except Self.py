class Solution(object):
    def productExceptSelf(self, nums):
        res=[]
        temp,count=1,0
        for num in nums:
            if 0==num:
                count+=1
            else:
                temp*=num

        if 0==count:
            for num in nums:
                res.append(temp/num)
        else:
            for num in nums:
                if 0==num:
                    if count>1:
                        res.append(0)
                    else:
                        res.append(temp)
                else:
                    res.append(0)
        return res

