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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode *cur = h;
        while (cur->next != nullptr)
        {
            ListNode* delNode = cur->next;
            if (delNode->val == val)
            {
                cur->next = delNode->next;
                delete delNode;
            }
            else
            {
                cur = cur->next;
            }
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