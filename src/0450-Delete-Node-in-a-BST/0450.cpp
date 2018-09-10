#include <iostream>
#include <string>
#include <unordered_map>
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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) return nullptr;
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode* rootRight = root->right;
                delete root;
                return rootRight;
            }
            if (root->right == nullptr)
            {
                TreeNode* rootLeft = root->left;
                delete root;
                return rootLeft;
            }
            TreeNode* tmp = minTreeNode(root->right);
            tmp->right = removeMin(root->right);
            tmp->left = root->left;
            delete root;
            return tmp;
        }
    }
private:
    TreeNode* minTreeNode(TreeNode* root)
    {
        if (root->left == nullptr) return root;
        return minTreeNode(root->left);
    }

    TreeNode* removeMin(TreeNode* root)
    {
        if (root->left == nullptr)
        {
            TreeNode* rootRight = root->right;
            return rootRight;
        }
        root->left = removeMin(root->left);
        return root;
    }
};