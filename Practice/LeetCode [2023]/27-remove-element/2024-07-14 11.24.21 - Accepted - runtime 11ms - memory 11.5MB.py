class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if not nums:
            return 0
        
        c = 0
        for i in nums:
            if not i == val:
                nums[c] = i
                c += 1
        return c