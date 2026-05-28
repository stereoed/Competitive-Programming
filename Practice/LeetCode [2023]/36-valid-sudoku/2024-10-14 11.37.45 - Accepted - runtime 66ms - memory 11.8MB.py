class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

        Each row must contain the digits 1-9 without repetition.
        Each column must contain the digits 1-9 without repetition.
        Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
        """
        for row in board:
            seen = set()
            for value in row:
                if value.isdigit() and value in seen:
                    return False
                seen.add(value)

        for column in range(9):
            seen = set()
            for row in board:
                value = row[column]
                if value.isdigit() and value in seen:
                    return False
                seen.add(value)

        for i in range(1,10,3):
            for j in range(1,10,3):
                seen = set()
                for dX in range(-1,2):
                    for dY in range(-1,2):
                        x = i + dX
                        y = j + dY
                        if x >= len(board) or x < 0:
                            continue
                        if y >= len(board[0]) or y < 0:
                            continue
                        value = board[x][y]
                        if value.isdigit() and value in seen:
                            return False
                        seen.add(value)
        return True

        