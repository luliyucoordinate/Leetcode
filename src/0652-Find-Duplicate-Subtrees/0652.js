var findDuplicateSubtrees = function(root) {
    let res = [], m = {};
    let dfs = function(root) {
        if (!root) return "";
        let s = root.val + "," + dfs(root.left) + "," + dfs(root.right);
        m[s] = (m[s] || 0) + 1;
        if (m[s] == 2) res.push(root);
        return s;
    }
    dfs(root);
    return res;
};