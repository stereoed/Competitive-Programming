class Solution(object):
    def subsetsWithDup(self, nums):
        nums.sort()  # Sort to handle duplicates
        result = []
        
        def backtrack(start, subset):
            # Add the current subset to the result
            result.append(subset[:])
            
            # Explore each element starting from 'start' index
            for i in range(start, len(nums)):
                # Skip duplicate elements
                if i > start and nums[i] == nums[i - 1]:
                    continue
                
                # Include nums[i] in the subset
                subset.append(nums[i])
                backtrack(i + 1, subset)  # Recurse with the next index
                subset.pop()  # Backtrack to explore subsets without nums[i]

        backtrack(0, [])
        return result
