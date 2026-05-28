class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if n == 0:
            return True
        pots = 0
        i = 0
        l = len(flowerbed)
        while i < l:
            if i>0 and flowerbed[i - 1] == 1:
                i += 1
                continue
            if flowerbed[i] == 1:
                i += 2
                continue
            if i<l-1 and flowerbed[i + 1] == 1:
                i += 3
                continue

            i += 2
            pots += 1
            if pots >= n:
                return True
        return False