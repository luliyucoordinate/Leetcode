class Solution:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return None

        m, n = len(board), len(board[0])

        def _solve(i, j):
            if 0 <= i < m and 0 <= j < n and board[i][j] == 'O':
                board[i][j] = '*'
                list(map(_solve, (i+1, i-1, i, i), (j, j, j+1, j-1)))

        for i in range(m):
            list(map(_solve, (i, i), (0, n - 1)))

        for i in range(n):
            list(map(_solve, (0, m - 1), (i, i)))

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '*':
                    board[i][j] = 'O'


if __name__ == '__main__':
    board = [['X', 'X', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'X', 'O', 'X'], ['X', 'O', 'X', 'X']]
    Solution().solve(board)
    print(board)