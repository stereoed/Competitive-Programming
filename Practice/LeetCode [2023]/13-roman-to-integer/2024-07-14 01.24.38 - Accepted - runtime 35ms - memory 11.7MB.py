class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dictionary = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        result = 0
        for i in range(len(s)):
            if i+1 < len(s):
                if dictionary.get(s[i]) < dictionary.get(s[i+1]):
                    result -= dictionary.get(s[i])
                    continue
            result += dictionary.get(s[i])
        return result