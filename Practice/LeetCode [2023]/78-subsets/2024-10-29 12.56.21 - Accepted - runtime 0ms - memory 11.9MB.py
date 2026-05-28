class Solution(object):
    def subsets(self, nums):
        self.o = []
        self.nums = nums
        def rec(c_a, index):
            if index == len(self.nums):
                self.o.append(c_a[:])
                return
            rec(c_a, index + 1)
            c_a.append(self.nums[index])
            rec(c_a, index + 1)
            c_a.pop()
        rec([], 0)
        return self.o
            
        