type IntHeap []int

func (h IntHeap) Len() int {
    return len(h)
}

func (h IntHeap) Less(i, j int) bool {
    return h[i] > h[j]
}

func (h IntHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Pop() interface{} {  
    x := (*h)[(*h).Len()-1]
	*h = (*h)[:(*h).Len()-1]
    return x
}

func (h *IntHeap) Push(x interface{}) {  
    *h = append(*h, x.(int))
}

func lastStoneWeight(stones []int) int {
    h := new(IntHeap)
    for _, v := range stones {
        heap.Push(h, v)
    }
    
    for len(*h) > 1 {
        a, b := heap.Pop(h).(int), heap.Pop(h).(int)
        heap.Push(h, a - b)
    }
    if len(*h) == 1 {
        return (*h)[0]
    }
    return 0
}