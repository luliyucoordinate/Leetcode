class Solution:
    def fractionToDecimal(self, n, d):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        flag = True
        if n < 0:
            flag = not flag
            n = -n
        
        if d < 0:
            flag = not flag
            d = -d
            
        res = str(n // d)
        n %= d
        if n == 0:
            if not flag and res != "0":
                return "-" + res
            return res
        
        res += '.'
        m = dict()
        while n:
            if n in m:
                res = res[0:m[n]] + "(" + res[m[n]:] + ")"
                break
            else:
                m[n] = len(res)
                
            n *= 10
            res += str(n // d)
            n %= d
            
        return res if flag else "-" + res