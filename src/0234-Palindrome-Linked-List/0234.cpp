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
    bool isPalindrome(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        ListNode* lat = head->next;
        ListNode* pre = head;
        while (lat != nullptr && lat->next != nullptr)
        {
            lat = lat->next->next;
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        pre->next = nullptr;
        ListNode* p = nullptr;
        while (cur != nullptr)
        {
            ListNode* q = cur->next;
            cur->next = p;
            p = cur;
            cur = q;
        }
        while (p != nullptr && head != nullptr)
        {
            if (p->val != head->val) return false;
            p = p->next;
            head = head->next;
        }
        return true;
    }
};

int main()
{
    return 0;
}