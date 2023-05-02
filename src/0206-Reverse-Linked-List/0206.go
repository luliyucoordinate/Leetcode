package reverselinkedlist

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	var revHead *ListNode
	for head != nil {
		temp := head.Next
		head.Next = revHead
		revHead = head
		head = temp
	}
	return revHead
}
