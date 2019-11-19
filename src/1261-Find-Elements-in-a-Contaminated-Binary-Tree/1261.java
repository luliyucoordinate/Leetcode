class FindElements {
    public FindElements(TreeNode root) {
        root.val = 0;
        data.add(0);
        dfs(root);
    }
    
    private Set<Integer> data = new HashSet();
    
    private void dfs(TreeNode root) {
        if (root.left != null) {
            root.left.val = root.val*2 + 1;
            data.add(root.left.val);
            dfs(root.left);
        }
        if (root.right != null) {
            root.right.val = root.val*2 + 2;
            data.add(root.right.val);
            dfs(root.right);
        }
    }
    
    public boolean find(int target) {
        return data.contains(target);
    }
}