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
    ListNode* _merge(ListNode* head1, ListNode* head2)
    {
        if (head1 == nullptr)
        {
            return head2;
        }
        if (head2 == nullptr)
        {
            return head1;
        }
        ListNode* h = new ListNode(-1);
        ListNode* tmp = h;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                tmp->next = head1;
                head1 = head1->next;
            }
            else
            {
                tmp->next = head2;
                head2 = head2->next;
            }
            tmp = tmp->next;
        }
        if (head1 != nullptr)
        {
            tmp->next = head1;
        }
        if (head2 != nullptr)
        {
            tmp->next = head2;
        }
        ListNode* retNode = h->next;
        delete h;
        return retNode;

    }
    ListNode* sortList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* pre = head, *lat = head;
        while (lat->next != nullptr && lat->next->next != nullptr)
        {
            lat = lat->next->next;
            pre = pre->next;
        }
        lat = pre->next;
        pre->next = nullptr;
        return _merge(sortList(head), sortList(lat));
    }
};

int main()
{
    return 0;
}