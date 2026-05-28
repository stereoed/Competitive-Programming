class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """

        s = s.strip()
        sign = 1
        if len(s) == 0 or ((not s[0].isdigit()) and (s[0] != '-' and s[0] != '+')):
            return 0
        elif s[0] == '-':
            sign = -1

        if not s[1:].isdigit():
            for i in range(1, len(s)):
                if not s[i].isdigit():
                    s = s[:i]
                    break
        s = s.lstrip('0')
        int_a = int(s) if s != '' and (s[0].isdigit() or ((s[0] == '-' or s[0] == '+') and len(s)>1)) else 0
        if sign == 1:
            int_a = min(2147483647, int_a)
        else:
            int_a = max(-2147483648, int_a)
        return int_a
