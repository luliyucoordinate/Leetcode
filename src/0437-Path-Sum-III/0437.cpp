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
    int pathSum(TreeNode* root, int sum) 
    {
        if (root == nullptr) return 0;
        int result = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        dfs(root, 0, freq, result, sum);
        return result;
    }

private:
    void dfs(TreeNode* node, int pathSum, unordered_map<int, int>& freq, int& result, int sum)
    {
        pathSum += node->val;
        result += freq[pathSum - sum];
        ++freq[pathSum];
        if (node->left) dfs(node->left, pathSum, freq, result, sum);
        if (node->right) dfs(node->right, pathSum, freq, result, sum);
        --freq[pathSum]; 
    }
};