class Solution(object):
    def coinChange(self, coins, amount):
        if not amount:
            return 0
        coins = [coin for coin in coins if coin <= amount]
        if not coins:
            return -1
        if len(coins) == 1:
            return amount//coins[0] if not amount%coins[0] else -1
        if amount & 1 and not any(c & 1 for c in coins):
            return -1


        dp = [float('inf')] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0:  # Check if the coin can be used
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return dp[amount] if dp[amount] != float('inf') else -1

            
