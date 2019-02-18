class Solution:
    def isCousins(self, root: 'TreeNode', x: 'int', y: 'int') -> 'bool':
        q = [root]
        d, xd, yd = 0, -1, -2
        while q:
            for _ in range(len(q)):
                node = q.pop(0)
                if node.val == x:
                    xd = d
                if node.val == y:
                    yd = d
                if node.left and node.right and \
                    (node.left.val == x and node.right.val == y or\
                     node.left.val == y and node.right.val == x):
                    return False

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            d += 1
        return xd == yd