class Solution(object):
    def longestPalindrome(self, s):
        if not s:
            return ""
        
        if s == s[::-1]:
            return s
        
        self.longest = ""
        def expand_around_center(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1

            if (right - left - 1) > len(self.longest):
                self.longest = s[left + 1:right]
        
        for i in range(len(s)):
            expand_around_center(i, i)
            expand_around_center(i, i + 1)
        return self.longest
