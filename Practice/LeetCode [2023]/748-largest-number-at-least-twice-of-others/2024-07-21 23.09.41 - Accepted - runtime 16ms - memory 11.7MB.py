class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = max(nums)
        i = nums.index(m)
        nums.remove(m)
        if max(nums)*2 <= m:
            return i
        return -1
        