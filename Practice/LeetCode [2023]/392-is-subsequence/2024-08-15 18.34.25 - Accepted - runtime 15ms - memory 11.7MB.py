class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        index = 0
        for n in t + "o":
            if index == len(s):
                return True
            if n == s[index]:
                index += 1            
        return False