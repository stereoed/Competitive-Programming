class WordDictionary(object):

    def __init__(self):
        self.root = {}
        self.end = '*'

    def addWord(self, word):
        pointer = self.root
        for char in word:
            if char not in pointer:
                pointer[char] = {}
            pointer = pointer[char]
        pointer[self.end] = word

    def search(self, word):
        pointer = self.root
        def dfs(word, pointer):
            for index in range(len(word)):
                char = word[index]
                if char == ".":
                    for key in pointer:
                        if key != self.end and dfs(word[index+1:], pointer[key]):
                            return True
                    return False
                else:
                    if char in pointer:
                        pointer = pointer[char]
                    else:
                        return False
            if self.end in pointer:
                return True
            return False
        return dfs(word, pointer)

        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)