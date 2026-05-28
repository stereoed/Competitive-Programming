class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = []
        lengths = []
        l = len(s)
        if l == 1:
            return 1
        for i in range(l-1):
            for e in s[i:]:
                if dic.__contains__(e):
                    lengths.append(len(dic))
                    dic = []
                    break
                dic.append(e)
        #if (len(dic) > 1):
        lengths.append(len(dic))
        result = 0
        for length in lengths:
            print(length)
            if result < length:
                result = length
        return result