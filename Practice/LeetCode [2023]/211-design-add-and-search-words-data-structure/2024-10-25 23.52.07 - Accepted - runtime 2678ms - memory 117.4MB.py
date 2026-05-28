class TrieNode:
    def __init__(self):
        self.children = {}              # Maps characters to TrieNode
        self.is_end_of_word = False      # Marks end of a valid word

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()           # Root of the trie

    def addWord(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()  # Create a new node if character path doesn't exist
            node = node.children[char]            # Move to the next node
        node.is_end_of_word = True                # Mark the end of the word

    def search(self, word):
        def dfs(j, node):
            for i in xrange(j, len(word)):
                char = word[i]
                if char == '.':
                    # If the character is '.', try every possible path in children
                    for child in node.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False  # If no paths match
                else:
                    # Regular character: check if path exists
                    if char not in node.children:
                        return False
                    node = node.children[char]
            return node.is_end_of_word  # Check if we're at the end of a valid word

        return dfs(0, self.root)
