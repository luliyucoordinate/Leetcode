#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while (!q.empty())
        {
            vector<int> tmp;
            int qLen = q.size();
            for (int i = 0; i < qLen; ++i)
            {
                TreeNode *node = q.front(); q.pop();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if ( i % 2 == 0) reverse(tmp.begin(), tmp.end());
            result.push_back(tmp);
            ++i;
        }
        return result;
    }
};
int main()
{
    return 0;
}