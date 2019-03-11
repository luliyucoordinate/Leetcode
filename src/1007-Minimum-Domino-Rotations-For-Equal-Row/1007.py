class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        for i in range(1,7):
            if all(i == a or i == b for a,b in zip(A,B)):
                return  min(len(A)-A.count(i),len(B)-B.count(i))
            
        return -1