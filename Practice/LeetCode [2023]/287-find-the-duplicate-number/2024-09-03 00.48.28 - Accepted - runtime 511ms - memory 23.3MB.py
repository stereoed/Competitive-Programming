class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # O(N) time, O(1) space
        nums.sort()
        highest_num = 0
        for i in nums:
            if i > highest_num:
                highest_num = i
                continue
            return i
            
        

        