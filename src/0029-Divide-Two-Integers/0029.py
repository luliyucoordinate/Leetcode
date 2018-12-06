class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        pos = False if (dividend < 0) ^ (divisor < 0) else True
            
        res, divd, divs = 0, abs(dividend), abs(divisor)
            
        if divd < divs:
            return 0
        
        mod = 2**31
        while divs <= divd:
            mul, tmp = 1, divs
            while (tmp << 1) <= divd:
                mul <<= 1
                tmp <<= 1
            
            res += mul
            divd -= tmp
            
            if res == mod:
                break
                
        if pos and res == mod:
            res -= 1
              
        return res if pos else -res