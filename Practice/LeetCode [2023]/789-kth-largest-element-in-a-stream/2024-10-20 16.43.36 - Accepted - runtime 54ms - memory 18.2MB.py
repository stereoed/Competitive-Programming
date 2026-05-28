import heapq
class KthLargest(object):

    def __init__(self, k, nums):
        self.nums = []
        self.k = k
        if nums:
            self.nums = heapq.nlargest(k, nums)
            heapq.heapify(self.nums)

    def add(self, val):
        if self.k > len(self.nums):
            heapq.heappush(self.nums, val)
        else:
            heapq.heappushpop(self.nums, val)
        return self.nums[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)