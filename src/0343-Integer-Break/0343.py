class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """  
        if n <= 3:
            return n - 1
        
        result = 1
        while n > 4:
            n -= 3
            result *= 3

        return n * result


if __name__ == '__main__':
    n = 4
    print(Solution().integerBreak(n))