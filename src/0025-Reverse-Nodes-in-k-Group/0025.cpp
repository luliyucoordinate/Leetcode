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
    ListNode *reverseKGroup(ListNode *head, int k) 
    {
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* pre = h;
        ListNode* cur = head;
        int n = 0;
        while (cur != nullptr)
        {
            ++n;
            cur = cur->next;
        }
        while (n >= k)
        {
            cur = pre->next;
            for (int i = 0; i < k - 1; ++i)
            {
                ListNode* lat = cur->next;
                cur->next = lat->next;
                lat->next = pre->next;
                pre->next = lat;
            }
            pre = cur;           
            n -= k;
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