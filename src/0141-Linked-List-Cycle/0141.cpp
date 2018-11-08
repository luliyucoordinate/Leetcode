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
    bool hasCycle(ListNode *head) 
    {
        if (head == nullptr) return false;
        auto fast = head;
        auto slow = head;
        while (fast->next != nullptr and fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};