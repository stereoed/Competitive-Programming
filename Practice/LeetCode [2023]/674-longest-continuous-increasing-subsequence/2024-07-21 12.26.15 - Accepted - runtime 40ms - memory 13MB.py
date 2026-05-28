class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxLCIS = 0
        current = 0
        last = -10**9-1
        for i in nums:
            if i > last:
                current += 1
            else:
                maxLCIS = max(current, maxLCIS)
                current = 1
            last = i
        return max(current, maxLCIS)