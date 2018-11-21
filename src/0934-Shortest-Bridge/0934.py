class Solution:
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        x, y, r, c = 0, 0, len(A), len(A[0])
        for i in range(r):
            for j in range(c):
                if A[i][j] == 1:
                    x, y = i, j
                    break
            else:
                continue
            break

        d = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        visited = [[0]*c for _ in range(r)]
        islandA, result = list(), 0
        def _floodfill(i, j):
            if 0 <= i < r and 0 <= j < c and not visited[i][j] and A[i][j] == 1:
                visited[i][j] = 1
                islandA.append((i, j))
                for k in range(4):
                    _floodfill(i + d[k][0], j + d[k][1])

        _floodfill(x, y)
        while islandA:
            stack = list()
            for i, j in islandA:
                if i - 1 >= 0 and not visited[i-1][j]:
                    if A[i-1][j] == 1:
                        return result
                    else:
                        stack.append((i-1, j))
                        visited[i-1][j] = 1
                if i + 1 < r and not visited[i+1][j]:
                    if A[i+1][j] == 1:
                        return result
                    else:
                        stack.append((i+1, j))
                        visited[i+1][j] = 1
                if j - 1 >= 0 and not visited[i][j-1]:
                    if A[i][j-1] == 1:
                        return result
                    else:
                        stack.append((i, j-1))
                        visited[i][j-1] = 1
                if j + 1 < c and not visited[i][j+1]:
                    if A[i][j+1] == 1:
                        return result
                    else:
                        stack.append((i, j+1))
                        visited[i][j+1] = 1
            islandA = stack
            result += 1

        return result

        
if __name__ == "__main__":
    A = [[0,1,0],[0,0,0],[0,0,1]]
    print(Solution().shortestBridge(A))