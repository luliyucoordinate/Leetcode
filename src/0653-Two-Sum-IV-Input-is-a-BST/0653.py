class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        if not root:
            return False
        q, seen = [root], set()
        for i in q:
            if k - i.val in seen:
                return True
            
            seen.add(i.val)
            if i.left:
                q.append(i.left)
            if i.right:
                q.append(i.right)
        return False