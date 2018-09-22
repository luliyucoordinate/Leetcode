import math 
class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        mole = math.factorial(m)
        deno = math.factorial(n - r) * math.factorial(r)
        return int(mole/deno)  

if __name__ == "__main__":
    m, n = 7, 3
    print(Solution().uniquePaths(m, n))