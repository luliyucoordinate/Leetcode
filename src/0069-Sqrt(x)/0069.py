class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        res = x
        while res**2 > x:
            res = (res + x//res)//2
            
        return res