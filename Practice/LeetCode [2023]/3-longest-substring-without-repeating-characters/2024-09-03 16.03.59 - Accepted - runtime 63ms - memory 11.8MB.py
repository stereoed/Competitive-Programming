import re
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        word = ""
        mWord = ""
        for c in s:
            if c in word:
                if len(mWord) < len(word):
                    mWord = word
                word = word[word.find(c) +1:]
            word += c
            print(word)
        if len(mWord) < len(word):
                    mWord = word
        return len(mWord)
                
