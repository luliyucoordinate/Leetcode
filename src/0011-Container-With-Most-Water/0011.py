class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = 0
        r = len(height) - 1
        contain = 0
        while l < r:
            contain = max(contain, (r - l) * min(height[l], height[r]))
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1

        return contain

if __name__ == '__main__':
    height = [1,2,4,3]
    print(Solution().maxArea(height))
