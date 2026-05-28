class Solution(object):
    def maxSubArray(self, nums):
        max_subarray = -10**4 
        candidate = 0

        for number in nums:
            if number >= candidate + number:
                candidate = number
            else:
                candidate += number

            if candidate > max_subarray:
                max_subarray = candidate
        return max_subarray


