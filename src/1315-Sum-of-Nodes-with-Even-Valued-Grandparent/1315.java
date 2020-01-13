class Solution {
    public int sumEvenGrandparent(TreeNode root) {
        return dfs(root, 1, 1);
    }

    public int dfs(TreeNode node, int p, int gp) {
        if (node == null) return 0;
        return dfs(node.left, node.val, p) + 
        dfs(node.right, node.val, p) + 
        (gp % 2 == 0 ? node.val : 0);
    }
}