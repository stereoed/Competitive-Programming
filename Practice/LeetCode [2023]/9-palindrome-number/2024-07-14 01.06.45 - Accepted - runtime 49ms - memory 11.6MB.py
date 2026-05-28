class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0 or int(str(x)[::-1]) != x:
            return 0
        else:
            return 1
