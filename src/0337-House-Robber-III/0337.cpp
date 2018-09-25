#include <iostream>
#include <vector>
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
    int rob(TreeNode* root) 
    {
        vector<int> check = _rob(root);
        return max(check[0], check[1]);
    }
private:
    vector<int> _rob(TreeNode* root)
    {
        if (root == nullptr) return {0, 0};
        vector<int> l = _rob(root->left);
        vector<int> r = _rob(root->right);
        return {(l[1] + r[1] + root->val), max(l[0], l[1]) + max(r[0], r[1])};
    }
};
int main()
{    
    return 0;
}