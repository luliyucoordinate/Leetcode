class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return
        r, c, flag = len(matrix), len(matrix[0]), False
        for i in range(r):
            if matrix[i][0] == 0:
                flag = True
            for j in range(1, c):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        for i in range(1, r):
            for j in range(1, c):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0

        if matrix[0][0] == 0:
            for j in range(c):
                matrix[0][j] = 0

        if flag:
            for i in range(r):
                matrix[i][0] = 0

if __name__ == "__main__":
    matrix = [
  [1,0,2,2],
  [3,4,5,2],
  [1,3,0,5]
]
    Solution().setZeroes(matrix)
    print(matrix)