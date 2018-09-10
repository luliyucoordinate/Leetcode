#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> result;
        stack<TreeNode*> s;
        while (!s.empty() or root)
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();s.pop();
                result.push_back(root->val);
                if (result.size() >= k) break;
                root = root->right;
            }
        }
        return result[k - 1];
    }
};