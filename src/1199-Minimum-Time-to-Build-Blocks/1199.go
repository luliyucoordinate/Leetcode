type IntHeap []int

func (h IntHeap) Len() int {
    return len(h)
}

func (h IntHeap) Less(i, j int) bool {
    return h[i] < h[j]
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

func minBuildTime(blocks []int, split int) int {
    q := new(IntHeap)
    for _, v := range blocks {
        heap.Push(q, v)
    }
    
    for len(*q) > 1 {
        heap.Pop(q)
        y := (*q)[0]
        heap.Pop(q)
        heap.Push(q, y + split)
    }
    return (*q)[0]
}