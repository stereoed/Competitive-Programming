class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums) == len(set(nums)):
            return False
        for j in range(len(nums)):
            if len(nums[j:j+k+1]) != len(set(nums[j:j+k+1])):
                return True
        return False

