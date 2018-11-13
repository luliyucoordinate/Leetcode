#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Definition for a binary tree node.
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
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if (root == nullptr or L > R) return 0;
        if (root->val < L) return rangeSumBST(root->right, L, R);
        if (root->val > R) return rangeSumBST(root->left, L, R);
        return root->val + rangeSumBST(root->left, L, root->val - 1) +
                     rangeSumBST(root->right, root->val + 1, R);
    }
};


int main()
{
    return 0;
}
