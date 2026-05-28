import heapq
class Solution(object):
    def kClosest(self, points, k):
        heap = []
        for p in points:
            distance = p[0]**2 + p[1]**2
            heapq.heappush(heap, (distance, p))
        o = []
        for i in range(k):
            o += [heapq.heappop(heap)[1]]
        return o