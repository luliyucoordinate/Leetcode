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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        if (root == nullptr) return result;
        if (root->left == nullptr and root->right == nullptr)
        {
            result.push_back(to_string(root->val));
        }
        vector<string> left = binaryTreePaths(root->left);
        for (int i = 0; i < left.size(); ++i)
        {
            result.push_back(to_string(root->val) + "->" + left[i]);
        }
        vector<string> right = binaryTreePaths(root->right);
        for (int i = 0; i < right.size(); ++i)
        {
            result.push_back(to_string(root->val) + "->" + right[i]);
        }
        return result;
    }
};