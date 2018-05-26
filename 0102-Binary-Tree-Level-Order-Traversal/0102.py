# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ret = []
        if root == None:
            return ret

        from queue import Queue
        q = Queue()
        q.put((root, 0))
        while not q.empty():
            node, level = q.get()

            if level == len(ret):
                ret.append([])
                
            ret[level].append(node.val)

            if node.left != None:
                q.put((node.left, level + 1))

            if node.right != None:
                q.put((node.right, level + 1))

        return ret

def createTree(root):
    if root == None:
        return root

    Root = TreeNode(root[0])
    nodeQueue = [Root]
    index = 1
    front = 0
    while index < len(root):
        node = nodeQueue[front]
        
        item = root[index]
        index += 1
        if item != None:
            leftNumber = item
            node.left = TreeNode(leftNumber)
            nodeQueue.append(node.left)

        if index >= len(root):
            break

        item = root[index]
        index += 1
        if item != None:
            rightNumber = item
            node.right = TreeNode(rightNumber)
            nodeQueue.append(node.right)

    return Root

def printTree(root):
    if root != None:
        print(root.val)
        printTree(root.left)
        printTree(root.right)      

if __name__ == "__main__":
    root = [1,None,2,3]
    treeRoot = createTree(root)
    printTree(treeRoot)
    print(Solution().levelOrder(treeRoot))