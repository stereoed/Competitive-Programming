class Solution(object):
    def searchFirstLetters(self, board, letter):
            o = []
            for row in range(len(board)):
                for column in range(len(board[0])):
                    if board[row][column] == letter:
                        o.append([row, column])
            return o

    def exist(self, board, word):
        letter = word[0]
        candidates = self.searchFirstLetters(board, letter)

        def dfs(current, index):
            if index == len(word):
                return True

            letter = word[index]
            nextpos = self.next_pos(current, board, letter)

            for pos in nextpos:
                aux = board[pos[0]][pos[1]]
                board[pos[0]][pos[1]] = '*'
                if dfs(pos, index + 1):
                    return True
                board[pos[0]][pos[1]] = aux
            return False

        for candidate in candidates:
            aux = board[candidate[0]][candidate[1]]
            board[candidate[0]][candidate[1]] = '*'
            if dfs(candidate, 1):
                return True
            board[candidate[0]][candidate[1]] = aux
        return False

    def next_pos(self, pos, board, letter):
        o = []
        movement = [[1,0], [-1, 0], [0, 1], [0, -1]]
        for mov in movement:
            row = pos[0] + mov[0]
            col = pos[1] + mov[1]
            if 0 <= row < len(board) and 0 <= col < len(board[0]):
                if board[row][col] == letter:
                    o.append([row, col])
        return o