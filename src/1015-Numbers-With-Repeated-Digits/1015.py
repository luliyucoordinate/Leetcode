class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        L = list(map(int, str(N + 1)))
        res, n = 0, len(L)

        def A(m, n):
            return 1 if n == 0 else A(m, n - 1) * (m - n + 1)

        for i in range(1, n): 
            res += 9 * A(9, i - 1)
            
        seen = set()
        for i, x in enumerate(L):
            tmp = sum(y not in seen for y in range(0 if i else 1, x))
            res += tmp*A(9 - i, n - i - 1)
            if x in seen: 
                break
            seen.add(x)
        return N - res