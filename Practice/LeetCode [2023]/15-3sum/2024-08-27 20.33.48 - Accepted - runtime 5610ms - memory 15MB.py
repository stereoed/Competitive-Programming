class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        st = []

        l = len(nums)
        nums.sort()
        for i in range(l-2):
            left = i+1
            right = l - 1
            while left < right:
                v = nums[i] + nums[left] + nums[right]
                if v == 0:
                    a = [nums[i], nums[left], nums[right]]
                    if a not in st:
                        st.append(a)
                    left += 1
                elif v > 0:
                    right -= 1
                else:
                    left += 1
        return st