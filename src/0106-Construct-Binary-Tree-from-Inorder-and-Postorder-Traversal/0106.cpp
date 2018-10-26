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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (postorder.empty() or inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(*postorder.rbegin());
        vector<TreeNode*> stack = {root};
        unsigned int k = inorder.size()-1;
        for (int i = postorder.size() - 2; i >= 0; --i)
        {
            auto parent = *stack.rbegin();
            if (parent->val != inorder[k])
            {
                parent->right = new TreeNode(postorder[i]);
                stack.push_back(parent->right);
            }
            else
            {
                while (!stack.empty() and (*stack.rbegin())->val == inorder[k])
                {
                    parent = *stack.rbegin();
                    stack.pop_back();
                    --k;
                }
                parent->left = new TreeNode(postorder[i]);
                stack.push_back(parent->left);
            }
        }
        return root;
    }
};