class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = re.sub(' +', ' ', s).strip()
        if not s:
            return 0
        return len(s.split(' '))
        