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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            pre = cur;
            cur = cur->next;
            while (cur != nullptr && cur->val == pre->val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
        }
        return head;
    }
};

int main()
{
    return 0;
}