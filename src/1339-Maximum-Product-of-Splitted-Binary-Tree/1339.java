class Solution {
    private long res = 0, total = 0;
    
    public int maxProduct(TreeNode root) {
        total = dfs(root); dfs(root);
        return (int)(res % (int)(1e9 + 7));
    }

    private long dfs(TreeNode root) {
        if (root == null) return 0;
        long sub = root.val + dfs(root.left) + dfs(root.right);
        res = Math.max(res, sub * (total - sub));
        return sub;
    }
}