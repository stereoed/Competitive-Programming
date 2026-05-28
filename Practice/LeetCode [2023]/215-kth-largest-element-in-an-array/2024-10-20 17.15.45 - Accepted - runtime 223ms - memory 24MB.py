import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
        if k == 1:
            return max(nums)
        return heapq.nlargest(k, nums)[-1]
        