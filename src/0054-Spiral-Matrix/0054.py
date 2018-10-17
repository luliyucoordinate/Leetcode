class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result = list()
        if not matrix:
            return result
        r, c = len(matrix), len(matrix[0])        
        x1, y1, x2, y2 = 0, 0, c-1, r-1
        while x1 <= x2 and y1 <= y2:
            for i in range(x1, x2+1):
                result.append(matrix[y1][i])

            for j in range(y1+1, y2+1):
                result.append(matrix[j][x2])
            if x1 < x2 and y1 < y2:
                for i in range(x2-1, x1, -1):
                    result.append(matrix[y2][i])

                for j in range(y2, y1, -1):
                    result.append(matrix[j][x1])
            
            x1 += 1
            y1 += 1
            x2 -= 1
            y2 -= 1

        return result

if __name__ == "__main__":
    matrix = [[6,9,7]]
    print(Solution().spiralOrder(matrix))