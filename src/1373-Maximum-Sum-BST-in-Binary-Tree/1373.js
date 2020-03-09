var maxSumBST = function(root) {
    let maxv = 0;
    let dfs = function(root) {
        if (root == null) return [true, 0];
        
        let res = [true, root.val];
        if (root.left) {
            let l = dfs(root.left);
            if (l[0] && root.left.val < root.val) res[1] += l[1];
            else res[0] = false;
        }
        if (root.right) {
            let r = dfs(root.right);
            if (r[0] && root.right.val > root.val) res[1] += r[1];
            else res[0] = false;
        }
        
        if (res[0]) maxv = Math.max(maxv, res[1]);
        return res;
    }
    
    dfs(root);
    return maxv;
};