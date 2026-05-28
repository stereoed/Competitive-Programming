import re
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        word = ""
        o = 0
        for c in s:
            if c in word:
                o = max(o, len(word))
                word = word[word.find(c) +1:]
            word += c
        o = max(o, len(word))
        return o
                
