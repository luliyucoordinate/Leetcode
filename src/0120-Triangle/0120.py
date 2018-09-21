class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle:
            return 0
        
        for row in range(len(triangle) - 1, 0, -1):
            for col, _ in enumerate(triangle[row - 1]):
                triangle[row - 1][col] += min(triangle[row][col] ,triangle[row][col + 1])
        
        return triangle[0][0]

if __name__ == '__main__':
    triangle = [
                [2],
                [3,4],
                [6,5,7],
                [4,1,8,3]
                ]
    print(Solution().minimumTotal(triangle))