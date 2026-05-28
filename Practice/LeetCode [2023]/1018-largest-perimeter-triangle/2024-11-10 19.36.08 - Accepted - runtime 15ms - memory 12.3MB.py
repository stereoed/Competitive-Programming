class Solution(object):
    def largestPerimeter(self, nums):
        # If the side of a triangle are a,b,c then a+b>c for the triangle to be formed .
        nums.sort()
        for i in range(len(nums) -1, 1, -1):
            if nums[i]<nums[i-1]+nums[i-2]:
                return nums[i]+nums[i-1]+nums[i-2]
        return 0
        