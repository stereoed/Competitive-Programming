class Solution(object):
    def finalPrices(self, prices):
        """
        :type prices: List[int]
        :rtype: List[int]
        """
        stack = []
        for i in range(len(prices)):
            current_price = prices[i]
            while stack and stack[-1][0] >= current_price:    
                aux = stack.pop()
                prices[aux[1]] = aux[0] - current_price
            stack.append([current_price, i])
        return prices