import heapq
class Solution(object):
    def lastStoneWeight(self, stones):
        h = []
        for value in stones:
            heappush(h, -value)

        stones = h
        #print(stones)

        def smash_rocks(a, b):
            if a == b:
                return 0
            return a - b
        while len(stones) > 1:
            a = heapq.heappop(stones)
            b = heapq.heappop(stones)
            res = smash_rocks(a, b)
            #print(a, b, res)

            if res:
                heapq.heappush(stones, res)
            #print(stones)

        if not stones:
            return 0
        return -stones[0]
