class Solution {
    public int longestZigZag(TreeNode root) {
        dfs(root);
        return res;
    }
    
    private int res = 0;
    
    public int[] dfs(TreeNode root){
        if (root == null) return new int[]{-1, -1};
        int[] left = dfs(root.left);
        int[] right = dfs(root.right);
        res = Math.max(res, Math.max(left[1] + 1, right[0] + 1));
        return new int[]{left[1] + 1, right[0] + 1};
    }
}