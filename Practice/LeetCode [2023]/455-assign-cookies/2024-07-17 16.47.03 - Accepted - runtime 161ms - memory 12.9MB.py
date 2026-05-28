class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        counter = 0
        l = len(g)
        while s and g:
            min_greed = g[0]
            min_size = s[0]
            if min_size >= min_greed:
                g.pop(0)
                counter += 1
            s.pop(0)
        return counter
