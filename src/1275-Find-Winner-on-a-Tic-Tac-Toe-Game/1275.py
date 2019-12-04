class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        score, p = [[0]*8 for _ in range(2)], 0

        for i, j in moves:
            score[p][i] += 1
            score[p][3+j] += 1
            score[p][6] += (i == j)
            score[p][7] += (i+j == 2)
            if any(x == 3 for x in score[p]): 
                return ["A", "B"][p]
            p ^= 1 
            
        return "Draw" if len(moves) == 9 else "Pending"