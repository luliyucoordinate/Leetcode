class Solution:      
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        colnum = []
        rownum = []
        sqnum = [[0] * 3 for _ in range(3)]
        for i in range(9):
            colnum.append(set(tuple(range(1, 10))))
            rownum.append(set(tuple(range(1, 10))))
            
        for i in range(3):
            for j in range(3):
                sqnum[i][j] = set(tuple(range(1, 10)))
        
        empty = set()
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    int_element = int(board[i][j])
                    rownum[i].remove(int_element)
                    colnum[j].remove(int_element)
                    sqnum[i//3][j//3].remove(int_element)
                else:
                    empty.add((i,j))
                    
        self.DFS(empty, colnum, rownum, sqnum, board)
    
    def DFS(self, empty, colnum, rownum, sqnum, board):
        if len(empty) == 0:
            return True
        
        max_possible_len = 9
        for (r, c) in empty:
            possible = rownum[r] & colnum[c] & sqnum[r//3][c//3]
            if len(possible) <= max_possible_len:
                max_possible_len = len(possible)
                i, j = r, c
                
        if max_possible_len == 0:
            return False
        
        empty.remove((i, j))

        possible = rownum[i] & colnum[j] & sqnum[i//3][j//3]
        for num in possible:
            rownum[i].remove(num)
            colnum[j].remove(num)
            sqnum[i//3][j//3].remove(num)
            board[i][j] = str(num)
            if self.DFS(empty, colnum, rownum, sqnum, board):
                return True
            rownum[i].add(num)
            colnum[j].add(num)
            sqnum[i//3][j//3].add(num)
            board[i][j] = "."
            
        empty.add((i, j))
        return False

if __name__ == "__main__":
    board = [["5","3",".",".","7",".",".",".","."],
            ["6",".",".","1","9","5",".",".","."],
            [".","9","8",".",".",".",".","6","."],
            ["8",".",".",".","6",".",".",".","3"],
            ["4",".",".","8",".","3",".",".","1"],
            ["7",".",".",".","2",".",".",".","6"],
            [".","6",".",".",".",".","2","8","."],
            [".",".",".","4","1","9",".",".","5"],
            [".",".",".",".","8",".",".","7","9"]]

    Solution().solveSudoku(board)
    print(board)