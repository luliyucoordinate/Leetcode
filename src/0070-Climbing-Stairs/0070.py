class Solution:
    def _climbStairs(self, n, climb):
        if n == 0 or n == 1:
            return 1

        if n not in climb:
            climb[n] = self._climbStairs(n - 1, climb) + self._climbStairs(n - 2, climb)

        return climb[n]

    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        climb = dict()
        return self._climbStairs(n, climb)

if __name__ == '__main__':
    n = 3
    print(Solution().climbStairs(n))