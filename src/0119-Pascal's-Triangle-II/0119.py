class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        result = [[1]*(i+1) for i in range(rowIndex+1)]
        for i in range(rowIndex+1):
            for j in range(1,i):
                result[i][j] = result[i-1][j-1] + result[i-1][j]
        return result[rowIndex]

if __name__ == "__main__":
    numRows = 3
    print(Solution().getRow(numRows))