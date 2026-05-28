import re
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = re.sub("[\W_]","",s).lower()
        return s == s[::-1]
        