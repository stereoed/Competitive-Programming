import math

class Solution(object):
    dictio = dict()
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """

        if n < 4:
            return n

        dictio = self.dictio
        if n-1 in dictio:
            a = dictio.get(n-1)
        else:
            a = self.climbStairs(n-1)
            dictio.update({n-1:a})
        if n-2 in dictio:
            b = dictio.get(n-2)
        else:
            b = self.climbStairs(n-2)
            dictio.update({n-2:b})
        return a + b
