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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* t = even;
        while (even != nullptr && even->next != nullptr)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = t;
        return head;
    }
};

int main()
{
    return 0;
}