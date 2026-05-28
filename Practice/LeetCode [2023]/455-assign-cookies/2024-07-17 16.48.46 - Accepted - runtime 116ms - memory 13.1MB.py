class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """

        l, r = 0, 0

        g.sort()
        s.sort()

        while l < len(g) and r < len(s):
            if g[l] <= s[r]:
                l, r = l + 1, r + 1
            else:
                r += 1
        return l
        