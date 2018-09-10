#include <iostream>
#include <algorithm>
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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (p && q) return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        if (p == nullptr && q == nullptr) return true;
        else return false;
    }
};