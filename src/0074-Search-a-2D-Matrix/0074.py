class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        r, c = len(matrix), len(matrix[0])
        left, right = 0, r*c

        while left < right:
            mid = (left+right)//2
            m, n = mid//c, mid%c
            if matrix[m][n] == target:
                return True
            elif matrix[m][n] < target:
                left = mid + 1
            else:
                right = mid
            
        return False
        

if __name__ == "__main__":
    matrix = [
            [1,   3,  5,  7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
            ]
    target = 13
    print(Solution().searchMatrix(matrix, target))