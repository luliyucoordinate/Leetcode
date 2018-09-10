#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <deque>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pair<int, ListNode*>, deque<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> min_heap;
        for (ListNode* l : lists) 
        {
            if (l) min_heap.push(make_pair(l->val, l));
        }
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (!min_heap.empty()) 
        {
            cur->next = min_heap.top().second;
            cur = cur->next;
            min_heap.pop();
            if (cur->next) min_heap.push(make_pair(cur->next->val, cur->next));
        }
        ListNode *ret = head->next;
        delete head;
        return ret;
    }
};

int main()
{
    return 0;
}