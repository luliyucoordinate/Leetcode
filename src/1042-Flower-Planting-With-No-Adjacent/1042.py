class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        res = [0] * N
        m = [[] for _ in range(N + 1)]
        for x, y in paths:
            m[x].append(y)
            m[y].append(x)
        for i in range(1, N+1):
            res[i-1] = ({1, 2, 3, 4} - {res[j-1] for j in m[i]}).pop()
        return res