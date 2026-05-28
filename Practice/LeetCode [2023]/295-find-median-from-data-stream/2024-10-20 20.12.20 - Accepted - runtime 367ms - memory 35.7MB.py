import heapq

class MedianFinder:
    def __init__(self):
        self.max_heap = []  # Max-Heap for the lower half
        self.min_heap = []  # Min-Heap for the upper half

    def addNum(self, num):
        # Add to max-heap (lower half) if the heap is empty or the number is less than or equal to the max
        if not self.max_heap or num <= -self.max_heap[0]:
            heapq.heappush(self.max_heap, -num)  # Store negative for max-heap behavior
        else:
            heapq.heappush(self.min_heap, num)  # Add to min-heap (upper half)

        # Rebalance the heaps if necessary
        if len(self.max_heap) > len(self.min_heap) + 1:
            moved_value = -heapq.heappop(self.max_heap)
            heapq.heappush(self.min_heap, moved_value)
        elif len(self.min_heap) > len(self.max_heap):
            moved_value = heapq.heappop(self.min_heap)
            heapq.heappush(self.max_heap, -moved_value)

    def findMedian(self):
        #print(self.max_heap, self.min_heap)
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]  # Max-Heap root is the median
        else:
            total = float(-self.max_heap[0] + self.min_heap[0])
            return (total/2)  # Average of both roots
