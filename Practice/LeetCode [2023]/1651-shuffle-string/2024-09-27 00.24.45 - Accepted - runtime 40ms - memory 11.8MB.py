class Solution(object):
    def restoreString(self, s, indices):
        word = [None] * len(s)
        
        for i in range(len(s)):
            word[indices[i]] = s[i]
            
        return ''.join(word)