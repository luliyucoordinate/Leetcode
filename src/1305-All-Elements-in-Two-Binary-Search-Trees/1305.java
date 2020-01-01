class Solution {
    private List<Integer> res = new ArrayList();
    
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        inOrder(root1);
        inOrder(root2);
        Collections.sort(res); 
        return res;
    }
    
    private void inOrder(TreeNode root) {
        if (root == null) return;
        inOrder(root.left);
        res.add(root.val);
        inOrder(root.right);
    }
}