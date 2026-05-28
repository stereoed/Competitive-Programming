class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s = list(s)
        s.sort()
        t = list(t)
        t.sort()
        return s == t