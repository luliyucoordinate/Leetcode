import math
class Solution:
    def numMusicPlaylists(self, N, L, K):
        """
        :type N: int
        :type L: int
        :type K: int
        :rtype: int
        """
        mem = [[0]*(L+1) for _ in range(N+1)]
        for i in range(K+1, N+1):
            for j in range(i, L + 1):
                if i == j or i == K + 1:
                    mem[i][j] = math.factorial(i)
                else:
                    mem[i][j] = mem[i-1][j-1]*i + mem[i][j-1]*(i - K)

        return mem[N][L]%(10**9 + 7)
        
if __name__ == "__main__":
    N = 2
    L = 3
    K = 1
    print(Solution().numMusicPlaylists(N, L, K))