# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return None
        
        copy_node = UndirectedGraphNode(node.label)
        visited = {node: copy_node}
        self.dfs(node, visited)
        return copy_node
        
    def dfs(self, node, visited):
        for i in node.neighbors:
            if i in visited:
                visited[node].neighbors.append(visited[i])
            else:
                copy_node_ne = UndirectedGraphNode(i.label)
                visited[node].neighbors.append(copy_node_ne)
                visited[i] = copy_node_ne
                self.dfs(i, visited)