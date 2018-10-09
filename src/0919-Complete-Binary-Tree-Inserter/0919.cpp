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
class CBTInserter 
{
public:
    CBTInserter(TreeNode* root) 
    {
        data.push_back(root);
        for (unsigned int i = 0;i < data.size(); ++i)
        {
            if (data[i]->left) data.push_back(data[i]->left);
            if (data[i]->right) data.push_back(data[i]->right);            
        }
    }
    
    int insert(int v) 
    {
        TreeNode* parent = data[(data.size() - 1)/2];
        if (parent->left)
        {
            parent->right = new TreeNode(v);
            data.push_back(parent->right);
        }
        else
        {
            parent->left = new TreeNode(v);
            data.push_back(parent->left);
        }
        return parent->val;
    }
    
    TreeNode* get_root() 
    {
        return data.front();
    }
private:
    vector<TreeNode *> data;
};

int main()
{
    return 0;
}