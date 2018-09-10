#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return _sortedArrayToBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode* _sortedArrayToBST(vector<int>& nums, int start, int end)
    {
        if (start > end) return nullptr;
        int mid = (end - start) / 2 + start;
        TreeNode* midNode = new TreeNode(nums[mid]);
        midNode->left = _sortedArrayToBST(nums, start, mid - 1);
        midNode->right = _sortedArrayToBST(nums, mid + 1, end);
        return midNode;
    }
};