class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        l = [root]
        while l:
            pre, l = l, [child for p in l for child in [p.left, p.right] if child]
        return sum(node.val for node in pre)