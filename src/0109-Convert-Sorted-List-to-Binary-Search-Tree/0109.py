class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head:
            return 
        
        if not head.next:
            return TreeNode(head.val)
        
        slow, fast = head, head.next.next # fast
        while fast and fast.next:
            slow = slow.next 
            fast = fast.next.next
            
        tmp = slow.next
        slow.next = None
        res = TreeNode(tmp.val)
        res.left = self.sortedListToBST(head)
        res.right = self.sortedListToBST(tmp.next)
        return res