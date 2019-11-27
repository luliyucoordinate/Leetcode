class Solution:
    def countServers(self, A: List[List[int]]) -> int:
        r, c = list(map(sum, A)), list(map(sum, zip(*A)))
        return sum(r[i] + c[j] > 2 for i in range(len(A)) for j in range(len(A[0])) if A[i][j])