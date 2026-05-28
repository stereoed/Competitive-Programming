class Solution(object):
    def permute(self, nums):
        self.o = []
        def rec(arr, nums):
            if not nums:
                self.o.append(arr[:])
            
            for index in range(len(nums)):
                n_copy = nums[:]
                num = n_copy.pop(index)
                rec(arr + [num], n_copy)
                
        rec([], nums)
        return self.o


        
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