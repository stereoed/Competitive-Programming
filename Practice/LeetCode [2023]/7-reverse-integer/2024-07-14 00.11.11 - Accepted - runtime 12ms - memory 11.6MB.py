class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        a = str(x)[::-1]
        fi = a[0]
        if x < 0:
            a = '-' + a[:-1]
            fi = a[1]
        int_a = int(a)
        if int_a.__abs__() > 2147483647:
            return 0
        return int_a