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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* p = h, *q = h;
        ++n;
        while (n-- != 0)
        {
            q = q->next;
        }
        while (q != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        ListNode* retNode = h->next;
        delete h;
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        return retNode;
    }
};

int main()
{
    return 0;
}