class WordDictionary:
    def __init__(self):
        self.trie = {}
        self.end_marker = '*'  # Special character to mark end of word
    
    def addWord(self, word):
        node = self.trie
        for char in word:
            if char not in node:
                node[char] = {}
            node = node[char]
        node[self.end_marker] = word  # Store the complete word at the end

    def buildTrie(self, words):
        for word in words:
            self.addWord(word)

class Solution:
    def findWords(self, board, words):
        # Initialize the trie with the given words
        word_dict = WordDictionary()
        word_dict.buildTrie(words)
        trie = word_dict.trie
        
        # Dimensions of the board
        rows, cols = len(board), len(board[0])
        result = set()  # To store found words without duplicates

        # DFS with backtracking
        def dfs(r, c, node, seen):
            char = board[r][c]
            if char not in node:
                return  # Early exit if the character is not in the current trie node
            
            # Move to the next node in the trie
            next_node = node[char]
            
            # Check if we have reached a complete word
            if word_dict.end_marker in next_node:
                result.add(next_node[word_dict.end_marker])  # Add the found word to the result

            # Mark the cell as visited by adding it to seen
            seen.add((r, c))
            
            # Explore all four directions
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                # Check bounds and if the new cell hasn't been visited
                if 0 <= nr < rows and 0 <= nc < cols and (nr, nc) not in seen:
                    dfs(nr, nc, next_node, seen)

            # Backtrack: unmark the cell
            seen.remove((r, c))

        # Start DFS from every cell in the board
        for r in range(rows):
            for c in range(cols):
                if board[r][c] in trie:  # Start DFS if the cell's letter is in the trie
                    dfs(r, c, trie, set())

        return list(result)  # Convert result set to list for output
