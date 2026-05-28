class Solution(object):
    def permute(self, nums):
        self.output = []
        self.nums = nums
        self.backtrack(0, len(nums))
        return self.output
            
    def backtrack(self, start, finish):
        if start == finish:
            self.output.append(self.nums[:])
        
        for i in range(start, finish):
            self.nums[start], self.nums[i] = self.nums[i], self.nums[start]
            self.backtrack(start + 1, finish)
            self.nums[start], self.nums[i] = self.nums[i], self.nums[start]


        
'''
class Solution(object):
    def combinationSum(self, candidates, target):
        self.o = []
        self.candidates = candidates
        self.target = target
        
        def rec(arr, current_sum, index):
            # Nums are all positive, and so, once we reach the target, we cant go back
            if current_sum >= self.target:
                if current_sum == self.target:
                    self.o.append(arr[:])
                return

            # We have seen all elements in the array and still haven't reached target
            if index == len(self.candidates):
                return

            # Check if we add the next digit without this one
            rec(arr, current_sum, index + 1)

            # Check if we add the next digit with this one
            arr.append(self.candidates[index])
            current_sum += self.candidates[index]
            rec(arr, current_sum, index)
            
            # Pop the array to backtrack
            arr.pop()

        rec([], 0, 0)
        return self.o
'''