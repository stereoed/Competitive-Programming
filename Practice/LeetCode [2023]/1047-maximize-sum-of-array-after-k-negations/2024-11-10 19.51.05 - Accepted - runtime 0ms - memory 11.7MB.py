class Solution(object):
    def largestSumAfterKNegations(self, nums, k):
        nums.sort()
        for i, n in enumerate(nums):
            if n < 0 and k > 0:
                nums[i] = -n
                k -= 1
            else:
                break

        if k > 0 and k&1:
            nums.sort()
            nums[0] = -nums[0]
        return sum(nums)
