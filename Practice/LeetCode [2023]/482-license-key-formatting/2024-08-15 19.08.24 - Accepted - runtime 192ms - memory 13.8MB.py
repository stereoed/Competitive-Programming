import re


class Solution(object):
    def licenseKeyFormatting(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        s = list(re.sub('-', '', s).upper()[::-1])
        i = 1
        while i*k <= len(s) - i:
            s.insert(i * k + i - 1, '-')
            i += 1
        return ''.join(s)[::-1].strip('-')