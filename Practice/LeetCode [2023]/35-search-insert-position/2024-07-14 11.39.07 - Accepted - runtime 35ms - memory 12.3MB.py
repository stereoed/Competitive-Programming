class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        try:
            return nums.index(target)
        except:
            c = 0
            for i in nums:
                if i > target:
                    return c
                c += 1
        return len(nums)


