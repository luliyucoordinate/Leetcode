var twoSumBSTs = function(root1, root2, target) {
    var find = function(root, t) {
        if (!root) return false;
        if (root.val == t) return true;
        else if (t < root.val) return find(root.left, t);
        else return find(root.right, t);
    }
    if (!root1) return false;
    if (find(root2, target - root1.val)) return true;
    return twoSumBSTs(root1.left, root2, target) ||
        twoSumBSTs(root1.right, root2, target);
};