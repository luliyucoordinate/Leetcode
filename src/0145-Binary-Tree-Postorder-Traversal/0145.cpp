#include <iostream>
#include <string>
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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> st;

        while (!st.empty() || root != nullptr)
        {
            if (root != nullptr)
            {
                st.push(root);
                result.insert(result.begin(), root->val);
                root = root->right;
            }
            else
            {
                TreeNode* node = st.top(); st.pop();
                root = node->left;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}