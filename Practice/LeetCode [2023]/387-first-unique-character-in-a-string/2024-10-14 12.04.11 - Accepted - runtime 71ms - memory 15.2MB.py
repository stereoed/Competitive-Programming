class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        seen = set()
        for i in range(len(s)):
            a = s[i]
            if a not in seen and s.count(a) == 1:
                return i
            seen.add(a)
        return -1

        