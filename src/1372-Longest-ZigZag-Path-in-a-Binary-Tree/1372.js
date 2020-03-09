var longestZigZag = function(root) {
    let res = 0;
    let dfs = function(root) {
        if (root == null) return [-1, -1];
        let left = dfs(root.left), right = dfs(root.right);
        res = Math.max(res, Math.max(left[1] + 1, right[0] + 1));
        return [left[1] + 1, right[0] + 1];
    }
    
    dfs(root);
    return res;
};