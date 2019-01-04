static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if (head == nullptr) return nullptr;
        RandomListNode* h1 = head, *h2 = head, *h = head;
        
        while (h1 != nullptr)
        {
            auto node = new RandomListNode(h1->label);
            node->next = h1->next;
            h1->next = node;
            h1 = node->next;
        }
        
        while (h2 != nullptr)
        {
            if (h2->random != nullptr) h2->next->random = h2->random->next;
            h2 = h2->next->next;
        }
        
        RandomListNode* res = h->next;
        while (h != nullptr)
        {
            auto tmp = h->next;
            h->next = tmp->next;
            if (h->next != nullptr) tmp->next = h->next->next;
            h = h->next;
        }
        return res;
    }
};