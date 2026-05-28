class Solution(object):
    def diStringMatch(self, s):
        l, r = 0, len(s)
        o = []
        for c in s:
            if c == "I":
                o.append(l)
                l += 1
            else:
                o.append(r)
                r -= 1
        o.append(l)
        return o

        