var removeLeafNodes = function(root, target) {
    if (root == null) return null;
    root.left = removeLeafNodes(root.left, target);
    root.right = removeLeafNodes(root.right, target);
    return root.val == target && root.left == root.right ? null : root;
};