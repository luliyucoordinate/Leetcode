#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) 
    {
        if (n == 0) return {};
        return _generateTrees(1, n);
    }
private:
    vector<TreeNode*> _generateTrees(int left, int right)
    {
        if (left > right) return {nullptr};
        vector<TreeNode*> res;
        for (int i = left; i <= right; ++i)
        {
            auto left_nodes = _generateTrees(left, i - 1);
            auto right_nodes = _generateTrees(i + 1, right);
            for (auto left_node : left_nodes)
            {
                for (auto right_node : right_nodes)
                {
                    auto root = new TreeNode(i);
                    root->left = left_node;
                    root->right = right_node;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};