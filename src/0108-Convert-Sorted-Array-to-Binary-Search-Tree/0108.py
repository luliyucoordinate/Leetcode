class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def _sortedArrayToBST(self, nums, start, end):
        if start > end:
            return None
        
        mid = (end - start)//2 + start
        midNode = TreeNode(nums[mid])
        midNode.left = self._sortedArrayToBST(nums, start, mid - 1)
        midNode.right = self._sortedArrayToBST(nums, mid + 1, end)
        return midNode 
        
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        return self._sortedArrayToBST(nums, 0, len(nums) - 1)