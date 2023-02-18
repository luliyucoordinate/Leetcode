class Solution {
 public:
  int minDiffInBST(TreeNode* root) {
    int res = INT_MAX, pre = -1;
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
      if (node) {
        dfs(node->left);
        if (pre != -1) {
          res = min(res, node->val - pre);
        }
        pre = node->val;
        dfs(node->right);
      }
    };
    dfs(root);
    return res;
  }
};