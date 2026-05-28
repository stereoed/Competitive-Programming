class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        c = 0
        p = -690
        for i in nums:
            if i != p:
                nums[c] = i
                c += 1
            p = i
        return c
        