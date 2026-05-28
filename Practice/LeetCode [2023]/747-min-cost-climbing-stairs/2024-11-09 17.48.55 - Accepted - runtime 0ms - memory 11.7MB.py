class Solution(object):
    def minCostClimbingStairs(self, cost):
        prev1, prev2 = 0, 0
        for n in range(2, len(cost) + 1):
            current = min(prev1 + cost[n-1], prev2 + cost[n-2])
            prev1, prev2 = current, prev1
        return current
