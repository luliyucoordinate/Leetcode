class Solution 
{
public:
    int getDecimalValue(ListNode* head) 
    {
        int res = 0;
        while (head != nullptr)
        {
            res = (res << 1) | head->val;
            head = head->next;
        }
        return res;
    }
};