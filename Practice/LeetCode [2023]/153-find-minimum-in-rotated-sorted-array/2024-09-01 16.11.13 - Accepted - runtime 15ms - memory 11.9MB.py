class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right)//2
            if nums[left] < nums[right]:
                if nums[mid] < nums[left]:
                    right -= 1
                else:
                    right = mid - 1
            else:
                if nums[mid] < nums[right]:
                    left += 1
                else:
                    left = mid + 1
        return min(nums[right], nums[left]) if left < len(nums) else nums[right]
