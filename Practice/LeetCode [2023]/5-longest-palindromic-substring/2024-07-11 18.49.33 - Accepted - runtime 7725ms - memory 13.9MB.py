class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ls = []
        maxi = []
        l = len(s)
        for i in range(l-1):
            ln = i
            for e in range(l, i, -1):
                if s[i:e+1] == s[i:e+1][::-1]:
                    maxi.append(s[i:e+1])
                    ls.append(e-i+1)
                    break
        return maxi[ls.index(max(ls))] if ls != [] else s[0]