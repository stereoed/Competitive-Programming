class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        counter = 0
        try:
            while True:
                nums.remove(0)
                counter += 1
        except:
            nums.extend([0] * counter)