import collections

class Solution:
    def _exist(self, board, i, j, word, k):
        if k == len(word):
            return True
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[i]):
            return False
        
        if board[i][j] == word[k]:
            temp = board[i][j]
            board[i][j] = '#'
            for d in range(4):
                if self._exist(board, i + self.direct[d][0], j + self.direct[d][1], word, k + 1):
                    return True

            board[i][j] = temp
        
        return False
   
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return False
        
        board_c = collections.Counter([c for row in board for c in row])
        word_c = collections.Counter(word)
        for c in word_c:
            if not c in word_c or word_c[c] > board_c[c]:
                return False
            
        r, c = len(board), len(board[0])
        self.direct = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        
        for i in range(r):
            for j in range(c):  
                if board[i][j] == word[0] and self._exist(board, i, j, word, 0):
                    return True
        
        return False

if __name__ == '__main__':
    board =[
            ['A','B','C','E'],
            ['S','F','C','S'],
            ['A','D','E','E']
            ]
    word = 'ABCCED'
    print(Solution().exist(board, word))
