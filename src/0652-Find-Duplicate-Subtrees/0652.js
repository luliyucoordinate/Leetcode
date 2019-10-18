var findDuplicateSubtrees = function(root) {
    let res = [], m = new Map();
    let dfs = function(root) {
        if (!root) return "";
        let s = root.val + "," + dfs(root.left) + "," + dfs(root.right);
        m.set(s, (m.get(s) || 0) + 1);
        if (m.get(s) == 2) res.push(root);
        return s;
    }
    dfs(root);
    return res;
};