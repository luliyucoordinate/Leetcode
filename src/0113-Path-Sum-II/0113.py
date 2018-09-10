# class Solution:
#     def pathSum(self, root, sum):
#         """
#         :type root: TreeNode
#         :type sum: int
#         :rtype: List[List[int]]
#         """    
#         result = list()
#         if not root:
#             return result

#         stack = [(list(), sum, root)]
#         while stack:
#             path, val_, node = stack.pop()

#             if node:
#                 path.append(node.val)
#                 if not node.left and not node.right and val_ == node.val:
#                     result.append(path)

#                 stack += [(path.copy(), val_ - node.val, node.left), (path.copy(), val_ - node.val, node.right)]

#         return result

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """   
        result = list()     
        if not root:
            return result
        
        self._pathSum(result, list(), root, sum)       
        return result
    
    def _pathSum(self,result, path, node, num):
        if node:
            path.append(node.val)
            
            if not node.left and not node.right and num == node.val:
                result.append(path.copy())
                return
            
            self._pathSum(result, path, node.left, num - node.val)
            self._pathSum(result, path, node.right, num - node.val)
            path.pop()  