static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if (root == nullptr) return;
        if (root->left != nullptr) root->left->next = root->right != nullptr ? root->right : findNext(root->next);
        if (root->right != nullptr) root->right->next = findNext(root->next);
        connect(root->right);
        connect(root->left);
    }
    
private:
    TreeLinkNode* findNext(TreeLinkNode* curr)
    {
        if (!curr) return nullptr;
        if (curr->left != nullptr) return curr->left;
        if (curr->right != nullptr) return curr->right;
        return findNext(curr->next);
    }
};