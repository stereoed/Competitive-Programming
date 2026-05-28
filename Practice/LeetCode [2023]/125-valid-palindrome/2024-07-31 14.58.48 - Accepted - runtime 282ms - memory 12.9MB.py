class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s_2 = ""
        for i in s:
            if i.isalnum():
                s_2 += i.lower()
        return s_2 == s_2[::-1]
        