#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty() or inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<TreeNode*> stack = {root};
        unsigned int k = 0;
        for (unsigned int i = 1; i < preorder.size(); ++i)
        {
            auto parent = *stack.rbegin();
            if (parent->val != inorder[k])
            {
                parent->left = new TreeNode(preorder[i]);
                stack.push_back(parent->left);
            }
            else
            {
                while (!stack.empty() and (*stack.rbegin())->val == inorder[k])
                {
                    parent = *stack.rbegin();
                    stack.pop_back();
                    ++k;
                }
                parent->right = new TreeNode(preorder[i]);
                stack.push_back(parent->right);
            }
        }
        return root;
    }
};