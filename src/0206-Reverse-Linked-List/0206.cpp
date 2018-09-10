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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            ListNode* lat = cur->next;
            cur->next = pre;
            pre = cur;
            cur = lat;
        }
        return pre;
    }
};
int main()
{
    return 0;
}