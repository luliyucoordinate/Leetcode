var sumEvenGrandparent = function(root) {
    let dfs = function(node, p, gp) {
        if (node == null) return 0;
        return dfs(node.left, node.val, p) +
            dfs(node.right, node.val, p) +
            (gp % 2 == 0 ? node.val : 0);
    }  
    return dfs(root, 1, 1);
};