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
    void reorderList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        ListNode* pre = head;
        ListNode* lat = head->next;
        while (lat != nullptr && lat->next != nullptr)
        {
            pre = pre->next;
            lat = lat->next->next;
        }

        ListNode* p = pre->next;
        pre->next = nullptr;

        ListNode* cur = nullptr;
        while (p != nullptr)
        {
            ListNode* q = p->next;
            p->next = cur;
            cur = p;
            p = q;
        }
        pre = head;
        while (pre != nullptr && cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = pre->next->next;
            cur = tmp;
        }
    }
};
int main()
{
    return 0;
}