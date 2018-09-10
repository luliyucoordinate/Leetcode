#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <tuple>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<int> path;
        vector<vector<int>> ret;
        _pathSum(path, ret, root, sum);
        return ret;  
    }
private:
    void _pathSum(vector<int>& path, vector<vector<int>>& ret, TreeNode* root,int sum)
    {
        if (root) 
        {
            path.push_back(root->val);
            
            if(root->left == nullptr and root->right == nullptr and root->val == sum)
                ret.push_back(path);

            _pathSum(path, ret, root->left, sum - root->val);
            _pathSum(path, ret, root->right, sum - root->val);
            path.pop_back(); 
        }            
    }
};