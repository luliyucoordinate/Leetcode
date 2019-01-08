#include <vector>

using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) 
    {
        pos = 0;
        return traverse(root, voyage) ? flips : vector<int>() = {-1};
    }
    
private:
    vector<int> flips;
    int pos;
    
    bool traverse(TreeNode* root, vector<int>& voyage) 
    {
        if (root == nullptr) return true;
        if (root->val != voyage[pos++]) return false;
        
        auto l = root->left, r = root->right;
        if (l != nullptr && l->val != voyage[pos]) 
        {
            flips.push_back(root->val);
            swap(l, r);
        }
        return traverse(l, voyage) && traverse(r, voyage);
    }
};