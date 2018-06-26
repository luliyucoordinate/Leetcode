# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# class Solution:
#     def __init__(self):
#         self.ret = []
        
#     def inorderTraversal(self, root):
#         """
#         :type root: TreeNode
#         :rtype: List[int]
#         """
#         if root != None:
#             self.inorderTraversal(root.left)
#             self.ret.append(root.val)
#             self.inorderTraversal(root.right)
            
#         return self.ret
class Solution:  
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = list()
        if root == None:
            return result
        
        stack = list()
        stack.append(root)
        while len(stack) != 0:
            top = stack.pop()
            if top.right != None:
                stack.append(top.right)
            result.append(top.val)
            if top.left != None:
                stack.append(top.left)
                       
        return result

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

        front += 1

    return Root

def printTree(root):
    if root != None:
        printTree(root.left)
        print(root.val)
        printTree(root.right)       
            
if __name__ == "__main__":
    root = [1,None,2,3]
    treeRoot = createTree(root)
    printTree(treeRoot)
    print(Solution().inorderTraversal(treeRoot))