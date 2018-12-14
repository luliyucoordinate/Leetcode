class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        cols, diag1, diag2 = set(), set(), set()
        
        def getResult(n, diag1, diag2, cols, row):
            if row == n:
                return 1
            
            res = 0
            for col in range(n):
                d1 = row + col
                d2 = row - col
                if d1 in diag1 or d2 in diag2 or col in cols:
                    continue
                    
                diag1.add(d1)
                diag2.add(d2)
                cols.add(col)
                res += getResult(n, diag1, diag2, cols, row + 1)
                diag1.remove(d1)
                diag2.remove(d2)
                cols.remove(col)
                
            return res
        
        return getResult(n, diag1, diag2, cols, 0)