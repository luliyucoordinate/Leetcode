class Solution:
    def deleteTreeNodes(self, n: int, parent: List[int], value: List[int]) -> int:
        for i in range(n-1, 0, -1):
            value[parent[i]] += value[i]
        
        zeros, isZero = 0, [0] * n
        for i in range(n):
            if parent[i] > 0 and isZero[parent[i]] or value[i] == 0:
                isZero[i] = 1
                zeros += 1
        return n - zeros