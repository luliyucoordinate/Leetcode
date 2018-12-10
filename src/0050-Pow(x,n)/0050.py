class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        m = -n if n < 0 else n
        p, q = 1, x
        while m > 0:
            if (m&1) == 1:
                p *= q
            m //= 2
            q *= q
            
        return 1/p if n < 0 else p