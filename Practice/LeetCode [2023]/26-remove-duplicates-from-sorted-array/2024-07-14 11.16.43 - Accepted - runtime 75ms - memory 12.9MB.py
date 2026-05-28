class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dic = []
        k = 0
        for i in range(len(nums)):
            if not dic.__contains__(nums[i]):
                dic.append(nums[i])
                nums[k] = nums[i]
                k += 1
        return k
        