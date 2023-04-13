#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    bool operator==(const ListNode &rhs) const
    {
        if (val != rhs.val)
        {
            return false;
        }
        if (next == nullptr && rhs.next == nullptr)
        {
            return true;
        }
        if (next == nullptr || rhs.next == nullptr)
        {
            return false;
        }
        return *next == *(rhs.next);
    }
};

#endif