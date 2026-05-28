class Solution(object):
    def balancedStringSplit(self, s):
        o, c = 0, 0
        for i in s:
            if i == "R":
                o += 1
            else:
                o -= 1
            
            if not o:
                c+= 1
        return c