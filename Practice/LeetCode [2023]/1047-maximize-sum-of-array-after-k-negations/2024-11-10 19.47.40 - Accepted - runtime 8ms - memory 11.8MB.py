import heapq
class Solution(object):
    def largestSumAfterKNegations(self, A, k):
        heapq.heapify(A)
        for _ in range(k):
            heapq.heappush(A, -heapq.heappop(A))
        return sum(A)
