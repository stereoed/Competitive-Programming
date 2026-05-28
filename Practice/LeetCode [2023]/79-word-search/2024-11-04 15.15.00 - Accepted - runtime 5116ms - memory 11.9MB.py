class Solution(object):
    def exist(self, board, word):
        rows, cols = len(board), len(board[0])

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