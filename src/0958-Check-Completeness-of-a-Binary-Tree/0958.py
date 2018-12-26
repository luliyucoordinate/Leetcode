class Solution:
    def isCompleteTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        nodes = [root]
        i = 0
        
        while nodes[i]:
            nodes.append(nodes[i].left)
            nodes.append(nodes[i].right)
            i += 1
            
        return not any(nodes[i:])