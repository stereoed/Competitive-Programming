class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic, ls = [], []
        l = len(s)
        for i in range(l-1):
            for e in s[i:]:
                if dic.__contains__(e):
                    ls.append(len(dic))
                    dic = []
                    break
                dic.append(e)
        ls.append(len(dic))
        return 1 if l == 1 else max(ls)