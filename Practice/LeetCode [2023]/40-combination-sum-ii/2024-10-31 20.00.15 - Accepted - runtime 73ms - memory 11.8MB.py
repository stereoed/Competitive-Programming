class Solution(object):
    def combinationSum2(self, candidates, target):
        self.o = []
        self.candidates = sorted(candidates)
        self.target = target
        
        def rec(arr, current_sum, index):
            # Nums are all positive, and so, once we reach the target, we cant go back
            if index == len(self.candidates) or current_sum >= self.target:
                if current_sum == self.target:
                    self.o.append(arr[:])
                return

            # Check if we add the next digit without this one
            i = index + 1
            while i < len(self.candidates) and self.candidates[i] == self.candidates[i-1]:
                i += 1
            rec(arr, current_sum, i)

            # Check if we add the next digit with this one
            arr.append(self.candidates[index])
            current_sum += self.candidates[index]
            rec(arr, current_sum, index + 1)
            
            # Pop the array to backtrack
            arr.pop()

        rec([], 0, 0)
        return self.o

'''
class Solution(object):
    def subsetsWithDup(self, nums):
        # Step 1: Create a frequency dictionary
        from collections import Counter
        freq = Counter(nums)  # Dictionary of number:count, e.g., {1: 1, 2: 2}
        unique_nums = sorted(freq.keys())  # Sorted list of unique elements
        result = []

        # Step 2: Backtracking function
        def backtrack(index, current_subset):
            if index == len(unique_nums):
                result.append(current_subset[:])  # Add a copy of the current subset
                return
            
            # Step 3: Current number and its count
            num = unique_nums[index]
            max_count = freq[num]

            # Step 4: Loop from 0 to max_count to add num multiple times
            for count in range(max_count + 1):  # range(max_count + 1) includes 0 to max_count
                # Add 'count' instances of num to the current subset
                current_subset.extend([num] * count)
                backtrack(index + 1, current_subset)
                # Backtrack: Remove 'count' instances of num from the current subset
                for _ in range(count):
                    current_subset.pop()

        # Start backtracking from the first unique number
        backtrack(0, [])
        return result
'''