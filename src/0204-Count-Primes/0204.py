class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        
        p = [1] * n
        for i in range(2, int(n ** 0.5) + 1):
            if p[i] == 1:
                p[i*i:n:i] = [0] * ((n - i*i - 1) // i + 1)
                
        return sum(p) - 2