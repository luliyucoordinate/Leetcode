/**
 * @param {TreeNode} root
 */
var FindElements = function(root) {
    this.data = new Set();
    root.val = 0;
    this.data.add(0);
    
    let dfs = node => {
        if (node.left) {
            node.left.val = node.val * 2 + 1;
            this.data.add(node.left.val);
            dfs(node.left);
        }
        if (node.right) {
            node.right.val = node.val * 2 + 2;
            this.data.add(node.right.val);
            dfs(node.right);
        }
    }
    dfs(root);
};

/** 
 * @param {number} target
 * @return {boolean}
 */
FindElements.prototype.find = function(target) {
    return this.data.has(target);
};