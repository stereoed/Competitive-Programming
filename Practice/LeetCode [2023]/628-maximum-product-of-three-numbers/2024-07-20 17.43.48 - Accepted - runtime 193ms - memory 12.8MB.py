class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        a = nums[-1]*nums[-2]*nums[-3]
        m, n = nums[0], nums[1]
        if m < 0 and n < 0:
            return max(a, nums[-1]*m*n)
        return a
        