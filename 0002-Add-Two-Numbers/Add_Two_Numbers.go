package main

import (
    "fmt"
)

type ListNode struct {
    Val int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    ret := new(ListNode)
    cur := ret
    add := 0
    
    for l1 != nil || l2 != nil || add > 0 {
		val1, val2 := 0, 0
		if l1 != nil {
			val1,l1 = l1.Val,l1.Next
		}
		if l2 != nil {
			val2,l2 = l2.Val,l2.Next
		}
		val := val1 + val2 + add
		add = val / 10
		cur.Next = &ListNode{Val:val%10, Next:nil}
		cur = cur.Next

	}
	return ret.Next
    
}

func main() {
	l1 := ListNode{Val:0, Next:nil}
	l1.Next = &ListNode{Val:4, Next:nil}
	l1.Next.Next = &ListNode{Val:3, Next:nil}
	l2 := ListNode{Val:0, Next:nil}
	l2.Next = &ListNode{Val:6, Next:nil}
	l2.Next.Next = &ListNode{Val:4, Next:nil}
	ret := addTwoNumbers(&l1, &l2)
    for ret != nil {
		fmt.Println(ret.Val)
		ret = ret.Next
	}
}
