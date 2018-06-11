# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
int __partition(T arr[], int l, int r){

    T v = arr[l];

    int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
        }

    swap( arr[l] , arr[j]);

    return j;
}

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        h = ListNode(x)
        h.next = head
        pre = h
        cur = head
        while cur != None:
            while pre.next.val < x:
                pre = pre.next

            cur = cur.next

        


def createList():
    head = ListNode(0)
    cur = head
    cur.next = ListNode(0)
    cur.next.next = ListNode(1)
    cur.next.next.next = ListNode(1)
    return head
            
def printList(head):
    cur = head
    while cur != None:
        print(cur.val, '-->', end='')
        cur = cur.next

    print('NULL')

if __name__ == "__main__":
    head = createList()
    printList(head)
    res = Solution().partition(head)
    printList(res)