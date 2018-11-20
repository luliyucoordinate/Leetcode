from ctypes import c_uint32
class Solution:
    hops = [(c_uint32 * 4)(4, 2, 2, 1)]
    def knightDialer(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N == 1:
            return 10
        
        mod = 10**9 + 7
        
        if N <= len(self.hops):
            H = self.hops[N - 1]
        else:
            H = self.hops[-1]
            for _ in range(len(self.hops), N):
                H = (c_uint32 * 4)(2*(H[1] + H[2]), 2*H[3] + H[0], H[0], H[1])
                for i in (0, 1, 2, 3):
                        H[i] %= mod
                self.hops.append(H)

        return sum(H) % mod

if __name__ == "__main__":
    N = 2
    print(Solution().knightDialer(N))