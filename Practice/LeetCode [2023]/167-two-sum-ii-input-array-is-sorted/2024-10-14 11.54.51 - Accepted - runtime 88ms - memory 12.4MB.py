class Solution(object):
    def twoSum(self, n, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = len(n)
        left = 0
        right = l - 1
        while left < right:
            v = n[left] + n[right]
            if v == target:
                return [left+1, right+1]
            elif v > target:
                right -= 1
            else:
                left += 1

        