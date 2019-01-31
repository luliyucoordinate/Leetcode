class Solution:
    def strWithout3a3b(self, A, B, a='a', b='b'):
        """
        :type A: int
        :type B: int
        :rtype: str
        """
        if B > A: 
            return self.strWithout3a3b(B, A, b, a)
        if A >= B * 2: 
            return (a + a + b) * B + a * (A - B * 2)
        return (a + a + b) * (A - B) + (a + b) * (B * 2 - A)