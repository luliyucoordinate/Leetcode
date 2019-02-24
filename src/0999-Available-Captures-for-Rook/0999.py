class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        R = None
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    R = (i, j)
                    break
        
        res = 0
        for x, y in [[0,1], [0,-1], [1,0], [-1,0]]:
            nx = x + R[0]
            ny = y + R[1]
            while 0 <= nx < 8 and 0 <= ny < 8:
                if board[nx][ny] == 'p':
                    res += 1
                    break
                if board[nx][ny] == 'B':
                    break
                nx += x
                ny += y
        return res