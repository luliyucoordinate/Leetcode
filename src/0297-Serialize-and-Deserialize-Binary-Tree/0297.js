/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    let res = "";
    let postOrder = function(root) {
        if (root == null) {
            res += "# "; return;
        }
        postOrder(root.left);
        postOrder(root.right);
        res += root.val + " ";
    }
    postOrder(root);
    return res;
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    let datas = data.split(" "); datas.pop();
    let deOrder = function() {
        let val = datas.pop();
        if (val == "#") return null;
        let root = new TreeNode(Number(val));
        root.right = deOrder();
        root.left = deOrder();
        return root;
    }
    return deOrder();
};