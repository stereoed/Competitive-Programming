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
        current = dictionary[s[0]]
        next = 0
        for i in range(len(s)):
            if i+1 < len(s):
                next = dictionary[s[i+1]]
                if current < next:
                    result -= current
                    current = next
                    continue
            result += current
            current = next
        return result