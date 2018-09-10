#include <iostream>
#include <climits>
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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* dummy = new ListNode(INT_MIN);
        for (ListNode* curr = head; curr != nullptr;) 
        {
            ListNode* pre = findInsertPoint(dummy, curr->val);
            ListNode* tmp = curr->next;
            curr->next = pre->next;
            pre->next = curr;
            curr = tmp;
        }
        return dummy->next;
    }
private:
    ListNode* findInsertPoint(ListNode* head, int val)
    {
        ListNode* pre = nullptr;
        for (ListNode* curr = head; curr != nullptr && curr->val <= val; pre = curr, curr = curr->next) {
            
        }
        return pre;
    }
};
class Solution { 
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) 
        {
            if (cur -> next && cur -> next -> val < cur -> val) 
            {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* h = new ListNode(-1);
        h->next = head;
        ListNode* cur = head;
        ListNode* lat = cur->next;
        while (lat != nullptr)
        {
            ListNode* tmp = h->next;
            ListNode* pre = h;
            while (tmp != lat && tmp->val < lat->val)
            {
                tmp = tmp->next;
                pre = pre->next;
            }
            if (tmp == lat)
            {
                cur = lat;
            }
            else
            {
                cur->next = lat->next;
                lat->next = tmp;
                pre->next = lat;
            }
            lat = cur->next;
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