from heapq import heappush, heappop
class MedianFinder:

    def __init__(self):
        # holds the smaller half
        self.max = []
        # holds the larger half
        self.min = []
        

    def addNum(self, num):
        heappush(self.max, -num)
        heappush(self.min, -heappop(self.max))
        if len(self.min) > len(self.max):
            heappush(self.max, -heappop(self.min))

        
    def findMedian(self):
        if len(self.max) == len(self.min):
            return (self.min[0] - self.max[0])/2.0
        else:
            return -self.max[0]