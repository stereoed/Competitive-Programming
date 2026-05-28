class Solution(object):
    def findMaxConsecutiveOnes(self, list):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not list or not list.__contains__(0):
            return len(list)
        i = list.index(0)
        return max(self.findMaxConsecutiveOnes(list[i+1:]), i)
