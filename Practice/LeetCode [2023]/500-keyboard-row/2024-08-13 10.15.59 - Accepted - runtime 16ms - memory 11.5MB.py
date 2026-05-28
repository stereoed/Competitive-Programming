class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        dic = {'a': 1, 'c': 2, 'b': 2, 'e': 0, 'd': 1, 'g': 1, 'f': 1, 'i': 0, 'h': 1, 'k': 1, 'j': 1, 'm': 2, 'l': 1, 'o': 0, 'n': 2, 'q': 0, 'p': 0, 's': 1, 'r': 0, 'u': 0, 't': 0, 'w': 0, 'v': 2, 'y': 0, 'x': 2, 'z': 2}
        o = []
        for word in words:
            w = word.lower()
            f = dic[w[0]]
            flag = True
            for letter in word:
                if dic[letter.lower()] != f:
                    flag = False
            if flag:
                o += [word]
        return o



            
                
                