class Solution:
    def bitwiseComplement(self, N: int) -> int:
        X = 1
        while X < N:
            X = (X << 1) + 1
        
        return N ^ X