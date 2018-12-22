static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (head == nullptr) return nullptr;
        TreeNode* res;
        if (head->next == nullptr) 
        {
            res = new TreeNode(head->val);
            return res;
        }
        
        ListNode* slow = head, *fast = head->next->next;
        while (fast != nullptr and fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        res = new TreeNode(tmp->val);
        res->left = sortedListToBST(head);
        res->right = sortedListToBST(tmp->next);
        return res;
    }
};