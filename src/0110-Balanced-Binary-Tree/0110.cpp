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
    bool isBalanced(TreeNode* root) 
    {
        return height(root) != -1;
    }
private:
    int height(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 or right == -1 or abs(left - right) > 1)
        {
            return -1;
        }
        return max(left, right) + 1;
    }
};
int main()
{
    return 0;
}