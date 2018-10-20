class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        matrix.reverse()
        for i in range(len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        

if __name__ == "__main__":
    matrix = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
    Solution().rotate(matrix)
    print(matrix)