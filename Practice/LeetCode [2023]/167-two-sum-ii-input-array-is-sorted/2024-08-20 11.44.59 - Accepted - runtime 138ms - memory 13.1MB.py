class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = len(numbers)
        for i in range(l):
            v = target - numbers[i]
            left = i + 1
            right = l - 1
            while left <= right:
                mid = (left + right) // 2
                if v == numbers[mid]:
                    return [i+1, mid+1]
                elif v < numbers[mid]:
                    right = mid-1
                else:
                    left = mid+1

        