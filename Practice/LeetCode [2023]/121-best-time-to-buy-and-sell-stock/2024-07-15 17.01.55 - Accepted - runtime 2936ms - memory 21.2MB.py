class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maximumProfit = 0
        absMax = max(prices)
        lowestPrice = 999999
        for i in range(len(prices)-1):
            price = prices[i]
            if lowestPrice <= price:
                continue
            else:
                lowestPrice = price
            if maximumProfit >= absMax - price or absMax == price:
                continue
            maxFromNow = max(prices[i+1:])
            maximumProfit = max(maximumProfit, maxFromNow-price)
        return maximumProfit