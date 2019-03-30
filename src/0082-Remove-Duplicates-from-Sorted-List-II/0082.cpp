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
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* pre = h;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            bool duplicate = false;
            while (cur->next != nullptr && cur->val == cur->next->val)
            {
                ListNode* delNode = cur;
                cur = cur->next;
                delete delNode;
                duplicate = true;
            }
            if (duplicate == false)
            {
                pre = cur;
                cur = cur->next;
            }
            else
            {
                pre->next = cur->next;
                ListNode* delNode = cur;
                cur = cur->next;
                delete delNode;
            }
        }
        ListNode* res = h->next;
        delete h;
        return res;
    }
};

int main()
{
    return 0;
}