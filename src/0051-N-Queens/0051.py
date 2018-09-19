class Solution:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        result, R, col, dia1, dia2 = list(), list(), list(), list(), list()
        col = [0 for i in range(n)]
        dia1 = [0 for i in range(2*n - 1)]
        dia2 = [0 for i in range(2*n - 1)]

        def generateBoard(m, row):
            board = [str() for i in range(n)]           
            for i in range(m):
                board[i] = row[i]*'.' + 'Q' + '.'*(m - row[i] - 1)

            return board

        def putQueen(m, index, row):
            if index == m:
                result.append(generateBoard(m, row))
                return

            for i in range(m):
                if not (col[i] or dia1[index + i] or dia2[index - i + m - 1]):
                    row.append(i)
                    col[i], dia1[index + i], dia2[index - i + m - 1] = 1, 1, 1
                    putQueen(m, index + 1, row)
                    col[i], dia1[index + i], dia2[index - i + m - 1] = 0, 0, 0
                    row.pop()

        putQueen(n, 0, R)
        return result

if __name__ == '__main__':
    n = 4
    print(Solution().solveNQueens(n))