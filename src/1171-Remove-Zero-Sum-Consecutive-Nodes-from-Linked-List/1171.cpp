class Solution 
{
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* du = new ListNode(0), *cur = du;
        du->next = head;
        int preSum = 0;
        map<int, ListNode*> m;
        while (cur) 
        {
            preSum += cur->val;
            if (m.count(preSum)) 
            {
                cur = m[preSum]->next;
                int p = preSum + cur->val;
                while (p != preSum) 
                {
                    m.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                m[preSum]->next = cur->next;
            } else m[preSum] = cur;
            cur = cur->next;
        }
        return du->next;
    }
};