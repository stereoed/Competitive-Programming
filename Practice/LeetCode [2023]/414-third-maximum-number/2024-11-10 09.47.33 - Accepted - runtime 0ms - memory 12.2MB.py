class Solution(object):
    def thirdMax(self, nums):
        nums = list(set(nums))
        nums.sort()
        return nums[-3] if len(nums) >= 3 else nums[-1]
        