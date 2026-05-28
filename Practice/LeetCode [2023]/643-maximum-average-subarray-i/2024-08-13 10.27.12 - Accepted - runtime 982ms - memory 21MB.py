class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        o = float(sum(nums[:k]))/k
        s = o
        for i in range(k, len(nums)):
            s = float((s*k - nums[i-k] + nums[i]))/k
            o = max(o, s)
        return o
