class Solution:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        cur = root
        while cur:
            if cur.left:
                pre = cur.left
                while pre.right:
                    pre = pre.right
                pre.right = cur.right
                cur.right = cur.left
                cur.left = None
                
            cur = cur.right