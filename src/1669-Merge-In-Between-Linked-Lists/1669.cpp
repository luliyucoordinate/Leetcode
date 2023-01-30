class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* p = list1;
    int aa = a;
    while (--aa) {
      p = p->next;
    }
    ListNode* x = p->next;
    int c = b - a;
    while (c--) {
      x = x->next;
    }
    p->next = list2;
    while (list2->next) {
      list2 = list2->next;
    }
    list2->next = x->next;
    return list1;
  }
};