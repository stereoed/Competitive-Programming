class Solution(object):
    def climbStairs(self, n):
        # Optimized approach:
        prev2, prev1 = 1, 1  # Base cases for 0 and 1 steps

        for i in range(2, n + 1):
            current = prev1 + prev2  # Number of ways to reach current step
            prev2 = prev1
            prev1 = current

        return prev1

        