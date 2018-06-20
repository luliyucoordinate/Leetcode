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
    vector<int> preorderTraversal(TreeNode* root) 
    {   
        vector<int> result;    
        if (root == nullptr) return result;
        
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* top = st.top(); st.pop();
            result.push_back(top->val);
            if (top->right != nullptr) st.push(top->right);
            if (top->left != nullptr) st.push(top->left);
        }

        return result;
    }
};
int main()
{
    return 0;
}