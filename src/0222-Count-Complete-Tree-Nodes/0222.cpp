#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
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
    int countNodes(TreeNode* root) 
    {
        int h = height(root);
        int result = 0;
        while (root)
        {
            if (height(root->right) == h - 1)
            {
                result += pow(2, h);
                root = root->right;
            }
            else
            {
                result += pow(2, h -1);
                root = root->left;
            }
            --h;
        }
        return result;
    }
private:
    int height(TreeNode* node)
    {
        int h = -1;
        while (node)
        {
            ++h;
            node = node->left;
        }
        return h;
    }
};