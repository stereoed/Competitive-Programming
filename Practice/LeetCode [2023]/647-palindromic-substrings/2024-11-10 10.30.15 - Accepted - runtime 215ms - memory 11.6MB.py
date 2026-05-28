class Solution(object):
    def countSubstrings(self, s):
        self.o = 0
        def expand_around_center(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
                self.o += 1
        
        for i in range(len(s)):
            expand_around_center(i, i)
            expand_around_center(i, i + 1)
        return self.o
        