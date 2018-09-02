#include <iostream>
#include <string>
#include <vector>
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while (root)
        {
            if (p->val < root->val and q->val < root->val)
            {
                root = root->left;
            }
            else if (p->val > root->val and q->val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
    }
};