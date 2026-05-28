class Solution(object):
    def numDecodings(self, s):
        if not s or s[0] == "0":
            return 0

        prev1, prev2 = 1, 1
        for i in range(1, len(s)):
            current = 0
            current += prev1 if s[i] != "0" else 0
            current += prev2 if int(s[i-1:i+1]) in range(10, 27) else 0
            
            if s[i] == '0' and (s[i - 1] != '1' and s[i - 1] != '2'):
                return 0
            prev2, prev1 = prev1, current
        return prev1
