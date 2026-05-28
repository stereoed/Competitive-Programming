class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num_set = set(nums)
        last = -1
        for i in num_set:
            if i != last + 1:
                return last + 1
            else:
                last = i
        return last+1