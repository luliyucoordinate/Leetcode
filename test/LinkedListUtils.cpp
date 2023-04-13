#include <stdexcept>
#include <vector>
#include "../util/ListNode.h"

using namespace std;

class LinkedListUtils {
public:
    static ListNode* contructLinkedList(vector<int> nums) {
        if (nums.empty()) {
            return nullptr;
        }
        ListNode* pre = new ListNode(-1);
        ListNode* head = new ListNode(nums[0]);
        pre->next = head;
        for (int i = 1; i < nums.size(); i++) {
            head->next = new ListNode(nums[i]);
            head = head->next;
        }
        return pre->next;
    }

    static ListNode* createSinglyLinkedList(vector<int> listValues) {
        if (listValues.empty()) {
            throw std::invalid_argument("Please pass in a valid listValues to create a singly linked list.");
        }
        ListNode* head = new ListNode(listValues[0]);
        ListNode* tmp = head;
        for (int i = 1; i < listValues.size(); i++) {
            ListNode* next = new ListNode(listValues[i]);
            tmp->next = next;
            tmp = tmp->next;
        }
        return head;
    }
};