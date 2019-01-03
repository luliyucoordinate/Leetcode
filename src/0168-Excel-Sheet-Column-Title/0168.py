class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = ''
        while n:
            n -= 1
            res += chr(ord('A')+n%26)
            n //= 26
            
        return res[::-1]