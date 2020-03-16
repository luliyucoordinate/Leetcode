var balanceBST = function(root) {
    let res = [];
    let inOrder = function(root) {
        if (root != null) {
            inOrder(root.left);
            res.push(root.val);
            inOrder(root.right);
        }
    }
    
    inOrder(root);
    
    let sortedToBST = function(l, r) {
        if (l > r) return  null;
        let mid = (l + r) >> 1;
        let root = new TreeNode(res[mid]);
        root.left = sortedToBST(l, mid - 1);
        root.right = sortedToBST(mid + 1, r);
        return root;
    }
    return sortedToBST(0, res.length - 1);  
};