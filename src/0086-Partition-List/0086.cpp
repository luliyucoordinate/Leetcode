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
    ListNode* partition(ListNode* head, int x) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* cur = head;
        ListNode* pre_min, *cur_min, *pre_max, *cur_max;
        pre_min = cur_min = new ListNode(-1);
        pre_max = cur_max = new ListNode(-1);
        while (cur != nullptr)
        {
            if (cur->val < x)
            {
                cur_min->next = cur;
                cur_min = cur_min->next;
            }
            else
            {
                cur_max->next = cur;
                cur_max = cur_max->next;
            }
            cur = cur->next;
        }
        cur_min->next = pre_max->next;
        cur_max->next = nullptr;
        ListNode* res = pre_min->next;
        delete pre_max;
        delete pre_min;
        return res;
    }
};


int main()
{
    return 0;
}