class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        boxTypes.sort(key= lambda x: x[1], reverse=True)
        o = 0
        i = 0
        while truckSize > 0:
            if i >= len(boxTypes):
                return o
            o += boxTypes[i][1] * min(truckSize, boxTypes[i][0])
            truckSize -= boxTypes[i][0]
            i += 1
        return o