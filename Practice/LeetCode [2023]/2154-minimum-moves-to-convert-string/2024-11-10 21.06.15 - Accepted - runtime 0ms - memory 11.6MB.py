class Solution(object):
    def minimumMoves(self, s):
        o = 0
        l = 0
        while l < len(s):
            if s[l] == "X":
                o += 1
                l += 2
            l += 1
        return o
        