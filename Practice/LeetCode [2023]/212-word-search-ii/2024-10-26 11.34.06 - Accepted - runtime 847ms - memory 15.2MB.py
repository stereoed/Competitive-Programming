class WordDictionary:
    def __init__(self):
        self.trie = {}
        self.end_marker = '*'

    def addWord(self, word):
        node = self.trie
        for char in word:
            if char not in node:
                node[char] = {}
            node = node[char]
        node[self.end_marker] = word

    def removeWord(self, word):
        node = self.trie
        stack = []
        for char in word:
            stack.append((node, char))
            node = node[char]
        del node[self.end_marker]
        while stack and not node:
            node, char = stack.pop()
            del node[char]

    def buildTrie(self, words):
        for word in words:
            self.addWord(word)

class Solution:
    def findWords(self, board, words):
        # Initialize the trie with the given words
        word_dict = WordDictionary()
        word_dict.buildTrie(words)
        trie = word_dict.trie
        
        rows, cols = len(board), len(board[0])
        result = set()

        def dfs(r, c, node):
            char = board[r][c]
            if char not in node:
                return
            
            next_node = node[char]
            
            if word_dict.end_marker in next_node:
                result.add(next_node[word_dict.end_marker])
                word_dict.removeWord(next_node[word_dict.end_marker])  # Remove found word to prune trie
            
            temp, board[r][c] = board[r][c], "#"  # Temporarily mark as visited
            
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != "#":
                    dfs(nr, nc, next_node)
                    
            board[r][c] = temp  # Unmark

        # Start DFS from each cell
        for r in range(rows):
            for c in range(cols):
                if board[r][c] in trie:
                    dfs(r, c, trie)

        return list(result)
