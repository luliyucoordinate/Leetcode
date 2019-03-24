class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0: 
            return -1
        
        r = 0
        for N in range(1, K + 1):
            r = (r * 10 + 1) % K
            if r == 0: 
                return N