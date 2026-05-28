class Solution(object):
    def minCostClimbingStairs(self, cost):
        dp = {0: 0, 1: 0}
        def dipro(n):
            if n in dp:
                return dp[n]
                
            dp[n] = min(dipro(n-1) + cost[n-1], dipro(n-2) + cost[n-2])
            return dp[n]
        return dipro(len(cost))
