class Solution:
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        N = N % 14
        if not N: 
            N = 14
            
        for _ in range(N):
            for i in range(1, len(cells) - 1):
                if cells[i-1] & 1 == cells[i+1] & 1:
                    cells[i] = 2 if not cells[i] & 1 else 3
                    
            for i in range(len(cells)):
                cells[i] >>= 1
                
        return cells  