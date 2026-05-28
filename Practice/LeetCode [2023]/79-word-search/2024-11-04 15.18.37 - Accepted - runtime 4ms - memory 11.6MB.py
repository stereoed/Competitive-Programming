class Solution(object):
    def exist(self, board, word):
        # Optimizacion hecha por optro wn, baja de 5000ms a 4 puto
        rows, cols = len(board), len(board[0])
        if len(word) > rows * cols:
            return False
        count = Counter(sum(board, []))
        for c, countWord in Counter(word).items():
            if count[c] < countWord:
                return False
        if count[word[0]] > count[word[-1]]:
            word = word[::-1]

        def dfs(row, col, index):
            # Check if the entire word is found
            if index == len(word):
                return True

            # Boundary and character match check
            if row < 0 or row >= rows or col < 0 or col >= cols or board[row][col] != word[index]:
                return False

            # Temporarily mark the cell as visited
            temp, board[row][col] = board[row][col], '*'

            # Explore all four directions
            found = (
                dfs(row + 1, col, index + 1) or
                dfs(row - 1, col, index + 1) or
                dfs(row, col + 1, index + 1) or
                dfs(row, col - 1, index + 1)
            )
            # Restore the cell value
            board[row][col] = temp
            return found

        for row in range(rows):
            for col in range(cols):
                if board[row][col] == word[0] and dfs(row, col, 0):
                    return True
        return False