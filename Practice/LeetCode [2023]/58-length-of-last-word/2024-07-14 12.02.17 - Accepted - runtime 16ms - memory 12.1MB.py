class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.rstrip()
        l = len(s)
        try:
            return l - s.rindex(' ') -1
        except:
            return l
