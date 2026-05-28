class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        counter = 0
        while nums.__contains__(0):
            nums.remove(0)
            counter += 1
        nums.extend([0] * counter)