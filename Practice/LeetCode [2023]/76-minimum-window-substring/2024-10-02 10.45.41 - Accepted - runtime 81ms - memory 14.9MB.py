class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        letterDict = {}

        if t in s:
            return t

        for letter in t:
            if letter in letterDict:
                letterDict[letter] += 1
            else:
                letterDict[letter] = 1

        currWindow, currLen = [], 0
        minLen, n = float("inf"), len(s)
        left = 0
        currLetterDict = {}
        required = len(letterDict)
        retLeft, retRight = 0, 0
        count = 0

        for right in range(n):
            letter = s[right]

            if letter in letterDict:
                if letter in currLetterDict:
                    currLetterDict[letter] += 1
                else:
                    currLetterDict[letter] = 1

                if currLetterDict[letter] == letterDict[letter]:
                    count += 1

            while count == required:
                # valid substring
                currLen = right - left + 1
                # update res
                if currLen < minLen:
                    minLen = currLen
                    retLeft, retRight = left, right
                
                # update new curr letter letterDict
                if s[left] in currLetterDict:
                    currLetterDict[s[left]] -= 1
                    if currLetterDict[s[left]] < letterDict[s[left]]:
                        count -= 1
                left += 1

        return s[retLeft:retRight+1] if minLen != float("inf") else ""