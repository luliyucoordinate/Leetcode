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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int result = 0;
        if (root == nullptr or (root->left == nullptr and root->right == nullptr)) return 0;
        if (root->left and root->left->left == nullptr and root->left->right == nullptr) result += root->left->val;
        result += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return result;
    }
};