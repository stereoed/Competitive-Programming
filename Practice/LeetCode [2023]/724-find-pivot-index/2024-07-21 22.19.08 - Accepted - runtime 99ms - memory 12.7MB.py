class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum_right = sum(nums)
        sum_left = 0
        for i in range(len(nums)):
            v = nums[i]
            sum_left += v
            if sum_right == sum_left:
                return i
            sum_right -= v
        return -1
