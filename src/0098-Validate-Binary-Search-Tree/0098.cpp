#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        return _isVaildBST(root, nullptr, nullptr);
    }
private:
    bool _isVaildBST(TreeNode* root, TreeNode* left, TreeNode* right)
    {
        if (root == nullptr) return true;
        if (left and left->val >= root->val) return false;
        if (right and right->val <= root->val) return false;
        return _isVaildBST(root->left, left, root) and _isVaildBST(root->right, root, right);
    }
};