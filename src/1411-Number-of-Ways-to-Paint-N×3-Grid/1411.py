class Solution:
    def numOfWays(self, n: int) -> int:
        aba, abc, mod = 6, 6, 10**9 + 7
        for i in range(n - 1):
            aba, abc = aba * 3 + abc * 2, aba * 2 + abc * 2
        return (aba + abc) % mod