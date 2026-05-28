class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        while len(nums) > 0:
            l = len(nums)
            a = nums.pop()
            if not nums.__contains__(a):
                return a
            else:
                nums.remove(a)
