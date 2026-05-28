class Solution(object):
    def findMaxConsecutiveOnes(self, list):
        """
        :type nums: List[int]
        :rtype: int
        """
        counterStart = -1
        maxLen = 0
        for i in range(len(list)):
            if list[i] == 0:
                maxLen = max(maxLen, i-counterStart-1)
                counterStart = i
        maxLen = max(maxLen, i - counterStart)
        return maxLen