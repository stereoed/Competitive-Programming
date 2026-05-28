class Solution(object):
    def rob(self, nums):
        if len(nums) == 1:
            return nums[0]

        prev1, prev2 = nums[0], 0
        for i in range(1, len(nums) - 1):
            prev1, prev2 = max(prev1, prev2 + nums[i]), prev1

        prev3, prev4 = nums[-1], 0
        for i in range(0, len(nums) - 2):
            prev3, prev4 = max(prev3, prev4 + nums[i]), prev3
        
        return max(prev1, prev3)