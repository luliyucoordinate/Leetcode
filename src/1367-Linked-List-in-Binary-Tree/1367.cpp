class Solution 
{
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        f.emplace_back(-1);
        int i = -1;
        ListNode* node = head;
        
        while (node != nullptr) 
        {
            while (i != -1 && node != nullptr && node->val != arr[i]) i = f[i];
            i++;
            f.emplace_back(i);
            arr.emplace_back(node->val);
            node = node->next;
        }
        
        return dfs(root, 0);
    }
private:
    vector<int> arr, f;
    
    bool dfs(TreeNode* node, int u) 
    {
        if (node == nullptr) return false;

        while (u != -1 && node->val != arr[u]) u = f[u];
        u++;

        if (u == arr.size()) return true;
        return dfs(node->left, u) || dfs(node->right, u);
    }
};