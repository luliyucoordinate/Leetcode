class Solution {
    public int maxSumBST(TreeNode root) {
        dfs(root);
        return maxv;
    }
    
    private int maxv = 0;
    
    private int[] dfs(TreeNode root) {
        if (root == null) return new int[]{1, 0};
        
        int[] res = new int[]{1, root.val};
        if (root.left != null) {
            int[] left = dfs(root.left);
            if (left[0] == 1 && root.left.val < root.val) res[1] += left[1];
            else res[0] = 0;
        }
        if (root.right != null) {
            int[] right = dfs(root.right);
            if (right[0] == 1 && root.right.val > root.val) res[1] += right[1];
            else res[0] = 0;
        }
        
        if (res[0] == 1) maxv = Math.max(maxv, res[1]);
        return res;
    }
}