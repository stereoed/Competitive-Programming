class Solution(object):
    def diStringMatch(self, s):
        right = len(s)
        left = 0
        o = []
        for c in s:
            if c == "I":
                o.append(left)
                left += 1
            else:
                o.append(right)
                right -= 1
        o.append(right)
        return o

        