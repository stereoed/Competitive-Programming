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
        while s and g:
            if s[0] >= g[0]:
                g.pop(0)
                counter += 1
            s.pop(0)
        return counter
