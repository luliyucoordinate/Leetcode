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
    int sumNumbers(TreeNode* root) 
    {
        int result = 0;
        _sumNumbers(root, 0, result);
        return result;
    }
private: 
    void _sumNumbers(TreeNode* root, int value, int& result)
    {
        if (root)
        {
            if (root->left == nullptr and root->right == nullptr)
                result += value*10 + root->val;
            _sumNumbers(root->left, value*10 + root->val, result);
            _sumNumbers(root->right, value*10 + root->val, result);
        }
    }
};