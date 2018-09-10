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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* pre = head;
        int count = 1;
        while (pre->next != nullptr)
        {
            ++count;
            pre = pre->next;
        }
        pre->next = head;
        int n = count - k % count;
        ListNode* q = pre;
        while (n--)
        {
            q = q->next;
        }
        ListNode* ret = q->next;
        q->next = nullptr;
        return ret;
    }
};

int main()
{
    return 0;
}