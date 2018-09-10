#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* h = new ListNode(-1);
        
        ListNode* cur = h;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 != nullptr && cur2 != nullptr)
        {
            if (cur1->val <= cur2->val)
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if (cur1 != nullptr)
        {
            cur->next = cur1;
        }
        if (cur2 != nullptr)
        {
            cur->next = cur2;
        }
        ListNode* retNode = h->next;
        delete h;
        return retNode;
    }
};

int main()
{
    return 0;
}