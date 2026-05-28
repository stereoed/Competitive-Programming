class Solution(object):
    def rob(self, nums):
        if len(nums) == 1:
            return nums[0]

        prev1, prev2 = nums[0], 0
        for i in range(1, len(nums)):
            prev1, prev2 = max(prev1, prev2 + nums[i]), prev1
        return prev1