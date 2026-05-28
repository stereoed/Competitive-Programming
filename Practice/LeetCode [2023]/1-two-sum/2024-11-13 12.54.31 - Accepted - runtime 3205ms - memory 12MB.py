class Solution(object):
    def twoSum(self, nums, target):
        i=0
        while i<len(nums)-1:
            k=i+1
            while k<len(nums):
                if nums[i]+nums[k]==target:
                    return [i,k]
                k=k+1
            i=i+1
        
        