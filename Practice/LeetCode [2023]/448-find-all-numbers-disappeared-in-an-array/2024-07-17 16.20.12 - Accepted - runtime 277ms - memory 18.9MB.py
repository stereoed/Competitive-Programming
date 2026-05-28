class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in range(len(nums)):
            n = abs(nums[i])-1
            nums[n] = -abs(nums[n])
        counter = 0
        for i in range(len(nums)):
            if not nums[i] < 0:
                nums[counter] = i + 1
                counter += 1
        return nums[:counter]