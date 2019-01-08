#include <stack>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class BSTIterator 
{
public:
    BSTIterator(TreeNode* root) 
    {
        pushLeft(root);
    }
    
    /** @return the next smallest number */
    int next() 
    {
        auto node = small.top(); small.pop();
        pushLeft(node->right);
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return small.empty() ? false : true;
    }
    
private:
    stack<TreeNode *> small;
    
    void pushLeft(TreeNode* node)
    {
        while (node)
        {
            small.push(node);
            node = node->left;
        }
    }
};