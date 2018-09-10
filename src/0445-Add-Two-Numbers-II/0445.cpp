#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
// class Solution 
// {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//     {
//         stack<int> stack1, stack2, result;
//         ListNode* h = new ListNode(-1);
//         ListNode*cur = h;
//         while (l1 != nullptr)
//         {
//             stack1.push(l1->val);
//             l1 = l1->next;
//         }
//         while (l2 != nullptr)
//         {
//             stack2.push(l2->val);
//             l2 = l2->next;
//         }
//         int add = 0;
//         while (!stack1.empty() || !stack2.empty() || add)
//         {
//             int top1 = 0;
//             int top2 = 0;
//             if (!stack1.empty())
//             {
//                 top1 = stack1.top();
//                 stack1.pop();
//             }    
//             if (!stack2.empty())
//             {
//                 top2 = stack2.top();
//                 stack2.pop();
//             } 
//             int val = top1 + top2 + add;
//             add = val/10;
//             result.push(val%10);         
//         }
//         while (!result.empty())
//         {
//             cur->next = new ListNode(result.top());
//             result.pop();
//             cur = cur->next;
//         }
//         ListNode* retNode = h->next;
//         delete h;
//         return retNode;
//     }
// };
class Solution {
    
    void backtrack(ListNode* proc) 
    {
        if (proc->next) 
        {
            backtrack(proc->next);
            if (proc->next->val >= 10) 
            {
                proc->val += proc->next->val / 10;
                proc->next->val %= 10;
            }
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *f1 = l1, *f2 = l2;
        while (f1 && f2) 
        {
            f1 = f1->next;
            f2 = f2->next;
        }
        
        ListNode *dummy = new ListNode(0), *proc = dummy;
        ListNode *s1 = l1, *s2 = l2;
        
        while (s1 || s2) 
        {
            if (f1) 
            {
                proc->next = s1;
                proc = proc->next;
                s1 = s1->next;
                f1 = f1->next;
            } else if (f2) 
            {
                proc->next = s2;
                proc = proc->next;
                s2 = s2->next;
                f2 = f2->next;
            } else 
            {
                proc->next = s1;
                proc->next->val += s2->val;
                proc = proc->next;
                s1 = s1->next;
                s2 = s2->next;
            }
        }
        
        backtrack(dummy);
        
        if (dummy->val != 0)
            return dummy;
        else 
        {
            ListNode* root = dummy->next;
            delete dummy;
            return root;
        }
    }
};
int main()
{
    return 0;
}