class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Requirements -> O(n) time, O(1) space, and no division
        # Multiply each result from the left
        n = len(nums)
        right = [None] * (n-1) + [nums[-1]]
        for i in range(n-2, -1, -1):
            right[i] = right[i+1]*nums[i] # suffix
        for i in range(1, n):
            nums[i] = nums[i-1]*nums[i]  # prefix
        o = [right[1]] + [None] * (n-2) + [nums[-2]]
        for i in range(1, n-1):
            o[i] = nums[i-1]*right[i+1]
        return o