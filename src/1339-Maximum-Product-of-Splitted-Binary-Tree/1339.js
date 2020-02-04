var maxProduct = function(root) {
    let total = 0, mod = 1000000007, res = 0;
    
    let dfs = function(root) {
        if (root == null) return 0;
        let sub = root.val + dfs(root.left) + dfs(root.right);
        res = Math.max(res, sub * (total - sub));
        return sub;
    }
    
    total = dfs(root);
    dfs(root);
    return res % mod;
};