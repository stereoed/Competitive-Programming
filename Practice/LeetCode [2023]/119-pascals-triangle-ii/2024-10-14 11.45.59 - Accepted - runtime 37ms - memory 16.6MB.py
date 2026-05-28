import math
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if floor == 0:
            return [[1]]
        result = []
        for k in range(rowIndex+1):
            result.append(math.comb(rowIndex,k))
        return result
    