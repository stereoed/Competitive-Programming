class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        boxTypes.sort(key= lambda x: x[1], reverse=True)
        o = 0
        while truckSize > 0:
            if not boxTypes:
                return o
            aux = boxTypes.pop(0)
            o += aux[1]*min(truckSize, aux[0])
            truckSize -= aux[0]
        return o