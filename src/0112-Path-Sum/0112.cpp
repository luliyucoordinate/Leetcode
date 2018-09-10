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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if (root == nullptr) return false;
        if (root->left == nullptr and root->right == nullptr) return sum == root->val;
        return hasPathSum(root->left, sum - root->val) or hasPathSum(root->right, sum - root->val);
    }
};