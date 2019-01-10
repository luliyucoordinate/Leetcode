class Solution:
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix: 
            return 0
        
        nums, area = [int(''.join(row), base=2) for row in matrix], 0
        
        for i in range(len(nums)):
            num = -1
            for j in range(i, len(nums)):
                num &= nums[j]
                
                if not num: 
                    break
                    
                n, l = num, 0
                while n:
                    l += 1
                    n &= n << 1
                    
                area = max(area, l * (j - i + 1))
                
        return area