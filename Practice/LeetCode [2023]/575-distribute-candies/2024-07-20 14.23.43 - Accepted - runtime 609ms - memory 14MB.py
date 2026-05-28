class Solution(object):
    def distributeCandies(self, candyType):
        """
        :type candyType: List[int]
        :rtype: int
        """
        n = len(candyType) / 2
        lCt = len(set(candyType))
        if n >= lCt:
            return lCt
        else:
            return n
