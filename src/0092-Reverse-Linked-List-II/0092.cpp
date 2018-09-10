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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if (head == nullptr || head->next == nullptr ||
            m >= n || m < 0 || n < 0)
        {
            return head;
        }
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* pre = h;
        ListNode* cur = head;
        int i = 1;
        for (; i < m && cur != nullptr; ++i)
        {
            pre = cur;
            cur = cur->next;
        }
        ListNode* t1 = pre;
        ListNode* t2 = cur;
        for (; i <= n && cur != nullptr; ++i)
        {
            ListNode* lat = cur->next;
            cur->next = pre;
            pre = cur;
            cur = lat;
        }
        t1->next = pre;
        t2->next = cur;
        return h->next;
    }
};

int main()
{
    return 0;
}