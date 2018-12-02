class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        M = ['', 'M', 'MM', 'MMM'] # 0,1000,2000,3000
        C = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'] # 0,100,200,300,...,900
        X = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'] # 0,10,20,30,...,90
        I = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'] # 0,1,2,3,...,9
        
        result = M[num//1000] + C[(num%1000)//100] + X[(num%100)//10] + I[num%10]
        return result