class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = list()
        res = 0
        heights.append(-1)
        for i, h in enumerate(heights):
            while stack and heights[stack[-1]] >= h:
                height_idx = stack.pop()
                pre_idx = stack[-1] if stack else -1
                res = max(res, heights[height_idx]*(i - pre_idx -1))

            stack.append(i)

        return res