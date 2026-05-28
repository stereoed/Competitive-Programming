class Solution(object):
    def validPalindrome(self, s):
        l, r = 0, len(s) - 1
        if s == s[::-1]:
            return True

        while l <= r:
            if s[l] != s[r]:
                return (s[l + 1:r + 1] == s[l + 1:r + 1][::-1] or s[l:r] == s[l:r][::-1])
            l += 1
            r -= 1
        return True
                
        