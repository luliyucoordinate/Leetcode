class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        seen = []
        
        for i, row in enumerate(board):
            for j, digit in enumerate(row):
                if digit != '.':
                    seen.append((i, digit))
                    seen.append((digit, j))
                    seen.append((i // 3, j // 3, digit))
        
        return len(seen) == len(set(seen))