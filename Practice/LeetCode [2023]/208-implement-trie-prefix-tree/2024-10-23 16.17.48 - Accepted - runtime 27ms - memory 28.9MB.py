class Trie(object):

    def __init__(self):
        self.root = {}
        

    def insert(self, word):
        """
        :type word: str
        :rtype: None
        """
        cur = self.root
        for char in word:
            if char not in cur:
                cur[char] = {}
            
            cur = cur[char]
        # pay attention here, not cur[char] = "#"
        cur["#"] = {}
        

    def search(self, word):
        """
        :type word: str
        :rtype: bool
        """
        cur = self.root
        for char in word:
            if char not in cur:
                return False
            cur = cur[char]
        return "#" in cur
        

    def startsWith(self, prefix):
        """
        :type prefix: str
        :rtype: bool
        """
        cur = self.root
        for char in prefix:
            if char not in cur:
                return False
            cur = cur[char]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)