#include <string>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string smallestFromLeaf(TreeNode* r) 
    {
        if (r == nullptr) return "|";
        auto s = string(1, 'a' + r->val);
        return r->left == r->right ? s : min(smallestFromLeaf(r->left) + s, smallestFromLeaf(r->right) + s);
    }
};