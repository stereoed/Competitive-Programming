class Solution(object):
    def numDecodings(self, s):
        if not s or s[0] == "0":
            return 0

        for i in range(1, len(s)):
            if s[i] == '0' and (s[i - 1] != '1' and s[i - 1] != '2'):
                return 0

        prev1, prev2 = 1, 1
        for i in range(1, len(s)):
            current = 0
            if s[i] != "0":
                current += prev1

            two_digit = int(s[i-1:i+1])
            if 10 <= two_digit <= 26:
                current += prev2

            prev2, prev1 = prev1, current
        return prev1
