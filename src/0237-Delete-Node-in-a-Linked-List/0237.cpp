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
    void deleteNode(ListNode* node) 
    {
        if (node == nullptr) return;
        if (node->next == nullptr) delete node;
        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = delNode->next;
        delete delNode;
    }
};

int main()
{
    return 0;
}