class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        counter = 0
        l = len(g)
        while s and g:
            min_greed = min(g)
            min_size = min(s)
            if min_size >= min_greed:
                g.remove(min_greed)
                counter += 1
            s.remove(min_size)
        return counter
