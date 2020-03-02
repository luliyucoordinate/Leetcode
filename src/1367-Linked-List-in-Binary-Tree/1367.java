class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        arr = new ArrayList();
        f = new ArrayList();
        f.add(-1);
        int i = -1;
        ListNode node = head;
        
        while (node != null) {
            while (i != -1 && node != null && node.val != arr.get(i)) i = f.get(i);
            i++;
            f.add(i);
            arr.add(node.val);
            node = node.next;
        }
        return dfs(root, 0);
    }
    
    private List<Integer> arr, f;
    
    private boolean dfs(TreeNode node, int u) {
        if (node == null) return false;
        
        while (u != -1 && node.val != arr.get(u)) {
            u = f.get(u);
        }
        u++;
            
        if (u == arr.size()) return true;
        return dfs(node.left, u) || dfs(node.right, u);
    }
}