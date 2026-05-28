class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        #Two pointer approach?
        s = list(s)
        vowels = set("AEIOUaeiou")
        l, r = 0, len(s)-1
        a = ''
        while l < r:
            while l < r and s[l] not in vowels:
                l += 1
            while l < r and s[r] not in vowels:
                r -= 1
            if not l < r:
                break
            a = s[l]
            s[l] = s[r]
            s[r] = a
            l += 1
            r -= 1
        o = ""
        for n in s:
            o += n
        return o
        