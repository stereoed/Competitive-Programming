class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        dic = {}
        words = s.split(" ")
        if len(words) != len(pattern):
            return False
        for i in range(len(words)):
            p = pattern[i]
            w = words[i]
            if p not in dic:
                if w in dic.values():
                    return False
                dic[p] = w
                continue
            if dic[p] != w:
                return False
        return True           
        