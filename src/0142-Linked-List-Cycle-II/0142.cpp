#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if (head == nullptr) return nullptr;
        auto fast = head;
        auto slow = head;
        auto entry = head;
        while (fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};