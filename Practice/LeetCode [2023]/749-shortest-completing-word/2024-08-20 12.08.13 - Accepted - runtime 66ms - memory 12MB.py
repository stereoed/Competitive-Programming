import re
class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        licensePlate = re.sub("[\d\s]", "", licensePlate).lower()
        w = ""
        l = 999999
        for word in words:
            print(word)
            if len(word) >= l:
                continue
            flag = True
            for c in licensePlate:
                if licensePlate.count(c) > word.count(c):
                    flag = False
                    break
            if flag:
                l = len(word)
                w = word
        return w
            
            
                    



        