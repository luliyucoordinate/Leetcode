var btreeGameWinningMove = function(root, n, x) {
    var tl, tr;
    function dfs(node) {
        if (node == null) return 0;
        var l = dfs(node.left), r = dfs(node.right);
        if (node.val == x) tl = l, tr = r;
        return l + r + 1;
    }
    dfs(root);
    return Math.max(tl, tr, n - tl - tr - 1) > n/2;
};