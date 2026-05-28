class Solution(object):
    def maxSubArray(self, nums):
        self.nums = nums
        curr =  0
        maxsum = float('-inf')
        for num in nums:
            curr += num
            if curr>maxsum:
                maxsum = curr
            
            if curr < 0:
                curr = 0
        return maxsum