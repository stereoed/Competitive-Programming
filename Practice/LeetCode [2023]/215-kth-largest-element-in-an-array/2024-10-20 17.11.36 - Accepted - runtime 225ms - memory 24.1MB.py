import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
        heap = heapq.nlargest(k, nums)
        return heap[-1]
        