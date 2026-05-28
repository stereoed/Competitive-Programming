class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        m = {}

        for num in nums:
            if num in m:
                m[num] += 1
            else:
                m[num] = 1
            
        h = []
        for key, value in m.items():
            heapq.heappush(h, (-value, key))

        res = []
        for _ in range(k):
            res.append(heapq.heappop(h)[1])
        return res