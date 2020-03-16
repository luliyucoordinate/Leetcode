class Solution {
    public TreeNode balanceBST(TreeNode root) {
        inOrder(root);
        return sortedToBST(0, res.size() - 1);
    }
    
    private List<Integer> res = new ArrayList();
    
    private void inOrder(TreeNode root) {
        if (root != null) {
            inOrder(root.left);
            res.add(root.val);
            inOrder(root.right);
        }
    }
    
    private TreeNode sortedToBST(int l, int r) {
        if (l > r) return  null;
        int mid = (l + r) >> 1;
        TreeNode root = new TreeNode(res.get(mid));
        root.left = sortedToBST(l, mid - 1);
        root.right = sortedToBST(mid + 1, r);
        return root;
    }
}