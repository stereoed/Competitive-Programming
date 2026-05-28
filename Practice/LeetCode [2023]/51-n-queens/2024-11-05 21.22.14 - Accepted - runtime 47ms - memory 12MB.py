class Solution(object):
    def print_solutions(self, n, queen_pos):
        board = [['.'] * n for _ in range(n)]
        for y, x in queen_pos:
            board[y][x] = 'Q'

        board = [''.join(row) for row in board]
        return board

    def is_candidate_position_valid(self, n, queen_pos, candidate_position):
        y_can, x_can = candidate_position
        for y, x in queen_pos:
            dx = x_can - x
            dy = y_can - y

            # Check for column conflicts and diagonal conflicts
            if x == x_can or abs(dx) == abs(dy):
                return False
        return True

    def solveNQueens(self, n):
        o = []

        def dfs(queen_pos, start_y, count):
            if count == n:
                o.append(self.print_solutions(n, queen_pos))
                return
            if start_y == n:  # Optional safety check
                return

            for x in range(n):
                candidate = [start_y, x]
                if self.is_candidate_position_valid(n, queen_pos, candidate):
                    queen_pos.append(candidate)
                    dfs(queen_pos, start_y + 1, count + 1)
                    queen_pos.pop(-1)

        dfs([], 0, 0)
        return o
