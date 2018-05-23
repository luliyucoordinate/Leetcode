#include <iostream>
// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ret = nullptr;
        ListNode** p = &ret;
        int add = 0;
        while (l1 || l2 || add)
        {
            int val = get_value(l1) + get_value(l2) + add;
            add = val / 10;
            ListNode* node = new ListNode(val % 10);
            *p = node;
            p = &((*p)->next);
            l1 = get_p(l1);
            l2 = get_p(l2);
        }
        return ret;
    }
private:
    int get_value(ListNode* l)
    {
        if (l != nullptr)
        {
            return l->val;
        }
        else
        {
            return 0;
        }
    }
    ListNode* get_p(ListNode* l)
    {
        if (l != nullptr)
        {
            return l->next;
        }
        else
        {
            return nullptr;
        }
    }
};

void deleteListNode(ListNode *l1)
{
    while (l1 != nullptr)
    {
        ListNode* p = l1->next;
        delete l1;
        l1 = p;
    }
}
int main()
{
    ListNode *l1 = new ListNode(0);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(0);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode * ret = Solution().addTwoNumbers(l1, l2);
    while (ret != nullptr)
    {
        std::cout << ret->val << std::endl;
        ret = ret->next;
    }
    deleteListNode(l1);
    deleteListNode(l2);
    deleteListNode(ret);
    return 0;
}