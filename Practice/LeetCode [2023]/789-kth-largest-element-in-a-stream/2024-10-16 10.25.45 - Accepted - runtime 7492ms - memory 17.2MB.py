class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        nums.sort()
        self.stream = nums[-k:]
        self.k = k

        if k > len(nums):
            self.stream = [-10**14]*(k-len(nums)) + self.stream
        
        

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        if val <= self.stream[0]:
            return self.stream[0]

        for i in range(1, len(self.stream)):
            if val <= self.stream[i]:
                self.stream = self.stream[1:i] + [val] + self.stream[i:]
                return self.stream[0]

        self.stream = self.stream[1:] + [val]
        return self.stream[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)