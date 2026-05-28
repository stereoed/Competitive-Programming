class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == s[::-1]:
            return s

        stt, end = 1, 0
        for i in range(1, len(s)):
            left, right = i-end, i+1
            s1, s2 = s[left-1:right], s[left:right]
            if left-1 >= 0 and s1 == s1[::-1]:
                stt = left-1
                end = end + 2
            elif s2 == s2[::-1]:
                stt = left
                end = end + 1
        
        return s[stt:stt+end] 