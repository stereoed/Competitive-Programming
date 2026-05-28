class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        idealList = [i + 1 for i in range(len(nums))]
        missingNum = (set(idealList) - set(nums)).pop()
        seen = set()
        for i in nums:
            if i in seen:
                return [i, missingNum]
            else:
                seen.add(i)
