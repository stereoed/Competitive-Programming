class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        lowest, highest = prices[0], prices[0]
        o = 0
        for p in prices:
            if p < lowest:
                o = max(o, highest - lowest)
                lowest = highest = p
            if p > highest:
                highest = p
        o = max(o, highest - lowest)
        return o