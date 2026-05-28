class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums)==2 and (nums[0]+nums[1]==target):
            return 0,1
        n = (len(nums)) - 1
        while(n!=0):
            if (target-nums[n])in nums:
                if nums.index(target-nums[n])!=n:
                    return nums.index(target-nums[n]),n
            n = n - 1