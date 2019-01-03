static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* h1 = headA, * h2 = headB;
        while (h1 != h2)
        {
            h1 = h1 == nullptr ? headB : h1->next;
            h2 = h2 == nullptr ? headA : h2->next;
        }
        return h1;
    }
};