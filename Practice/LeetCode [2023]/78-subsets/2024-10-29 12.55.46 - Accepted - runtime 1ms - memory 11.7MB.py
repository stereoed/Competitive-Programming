class Solution(object):
    def subsets(self, nums):
        self.o = []
        self.nums = nums
        
        def rec(c_a, index):
            if index == len(self.nums):
                self.o.append(c_a[:])  # Add a copy of current subset
                return
            
            # Exclude current element
            rec(c_a, index + 1)
            
            # Include current element
            c_a.append(self.nums[index])
            rec(c_a, index + 1)
            c_a.pop()  # Backtrack to remove the last element
        
        rec([], 0)
        return self.o
            
        