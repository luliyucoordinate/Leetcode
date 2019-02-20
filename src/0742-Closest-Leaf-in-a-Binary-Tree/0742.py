import collections
class Solution:
    def findClosestLeaf(self, root: 'List[TreeNode]', k: 'int') -> 'int':
        self.start = None
        self.buildGraph(root, None, k)
        q, visited = [root], set()
        self.graph = collections.defaultdict(list)
        while q:
            for i in range(len(q)):
                cur = q.pop(0)
                visited.add(cur)
                if not cur.left and not cur.right:
                    return cur.val
                for node in self.graph:
                    if node in visited:
                        q.append(node)

    def buildGraph(self, node, parent, k):
        if not node:
            return

        if node.val == k:
            self.start = node
        if parent:
            self.graph[node].append(parent)
            self.graph[parent].append(node)
        self.buildGraph(node.left, node, k)
        self.buildGraph(node.right, node, k)