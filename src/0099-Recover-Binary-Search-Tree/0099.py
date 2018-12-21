class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        cur, pre = root, None
        first, second = None, None
        stack = []
        
        while cur or stack:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:        
                node = stack.pop()
                if pre and pre.val >= node.val:
                    if not first:
                        first = pre
                    second = node
                    
                pre = node
                cur = node.right
        
        first.val, second.val = second.val, first.val