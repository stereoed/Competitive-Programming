class Solution(object):
    def subsetsWithDup(self, nums):
        self.o = []
        self.nums = nums
        def rec(c_a, index):
            if index == len(self.nums):
                b_a = sorted(c_a[:])
                if b_a not in self.o:
                    self.o.append(b_a[:])
                return
            rec(c_a, index + 1)
            c_a.append(self.nums[index])
            rec(c_a, index + 1)
            c_a.pop()
        rec([], 0)
        return self.o