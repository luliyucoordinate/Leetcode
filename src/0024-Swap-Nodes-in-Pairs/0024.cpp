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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* pre = h;
        while (pre->next != nullptr && pre->next->next != nullptr)
        {
            ListNode* node1 = pre->next;
            ListNode* node2 = node1->next;
            ListNode* lat = node2->next;
            pre->next = node2;
            node2->next = node1;
            node1->next = lat;
            pre = node1;
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