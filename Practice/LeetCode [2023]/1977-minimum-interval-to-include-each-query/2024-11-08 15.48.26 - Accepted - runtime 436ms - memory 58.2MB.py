import heapq

class Solution(object):
    def minInterval(self, intervals, queries):
        # Step 1: Sort intervals by their start points
        intervals.sort(key=lambda x: x[0])
        pointer, n = 0, len(intervals)

        # Step 2: Sort queries along with their original indices
        sorted_queries = [(q, idx) for idx, q in enumerate(queries)]
        sorted_queries.sort()

        # Step 3: Initialize result array and min-heap
        result = [-1] * len(queries)
        heap = []

        # Step 4: Process each query
        for query, original_index in sorted_queries:
            # Push relevant intervals to the heap (intervals starting before or at the query)
            while pointer < n and intervals[pointer][0] <= query:
                start, end = intervals[pointer]
                # Push (interval_size, end) to ensure the smallest interval size is at the top
                heapq.heappush(heap, (end - start + 1, end))
                pointer += 1

            # Remove intervals that cannot cover the current query
            while heap and heap[0][1] < query:
                heapq.heappop(heap)

            # If the heap is not empty, the top element is the smallest valid interval
            if heap:
                result[original_index] = heap[0][0]  # Store the size of the smallest interval

        return result
