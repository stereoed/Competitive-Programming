class Solution(object):
    def search(self, nums, target):
        start = 0
        end = len(nums) - 1
        while start < end:
            mid = (start + end) // 2
            if nums[mid] == target:
                return mid
            if abs(nums[start]-target) > abs(nums[end]-target):
                if abs(nums[mid]-target) < abs(nums[end]-target):
                    start += 1
                else:
                    start = mid + 1
            else:
                if abs(nums[mid]-target) < abs(nums[start]-target):
                    end -= 1
                else:
                    end = mid
        if nums[end] == target:
            return end
        return -1
