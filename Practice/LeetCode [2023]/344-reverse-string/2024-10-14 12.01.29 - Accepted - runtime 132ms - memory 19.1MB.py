class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        #Two pointer approach?
        l, r = 0, len(s)-1
        a = ''
        while l < r:
            a = s[l]
            s[l] = s[r]
            s[r] = a
            l += 1
            r -= 1
        