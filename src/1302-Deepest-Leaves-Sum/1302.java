class Solution {
    public int deepestLeavesSum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList();
        q.offer(root);
        int res = 0;
        
        while (!q.isEmpty()) {
            int n = q.size();
            res = 0;
            
            while (n-- > 0) {
                TreeNode cur = q.poll();
                res += cur.val;
                if (cur.right != null) q.offer(cur.right);
                if (cur.left != null) q.offer(cur.left); 
            }
        }
        return res;
    }
}