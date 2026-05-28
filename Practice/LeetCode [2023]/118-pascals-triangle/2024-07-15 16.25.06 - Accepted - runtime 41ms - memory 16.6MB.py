import math


class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        def level(floor):
            if floor == 0:
                return [[1]]
            result = []
            for k in range(floor+1):
                result.append(math.comb(floor,k))
            print(result)
            return level(floor-1) + [result]
        return level(numRows-1)

