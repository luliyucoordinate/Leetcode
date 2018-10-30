class Solution:
    def beautifulArray(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        result = [1]
        while len(result) < N:
            result = [i * 2 - 1 for i in result] + [i * 2 for i in result]
        return [i for i in result if i <= N]

if __name__ == "__main__":
    N = 4
    print(Solution().beautifulArray(N))