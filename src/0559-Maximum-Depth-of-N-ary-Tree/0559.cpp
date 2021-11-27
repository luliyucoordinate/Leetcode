class Solution {
 public:
  int maxDepth(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int res = 0;
    for (auto c : root->children) {
      res = max(res, maxDepth(c));
    }
    return res + 1;
  }
};