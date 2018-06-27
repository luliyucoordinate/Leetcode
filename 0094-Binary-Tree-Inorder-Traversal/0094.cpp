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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode *> st;

        while (!st.empty() || root != nullptr)
        {
            if (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top(); st.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};
int main()
{
    return 0;
}