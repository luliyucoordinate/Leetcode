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

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func maxEvents(events [][]int) int {
    sort.Slice(events, func(i, j int) bool {
        return events[i][0] < events[j][0]
    })
    q := new(IntHeap)
    res, index, n := 0, 0, len(events)
    
    l, r := 100000, 0
    for _, it := range events {
        l, r = min(l, it[0]), max(r, it[1])
    }

    for i := l; i <= r; i++ {
        for index < n && events[index][0] <= i {
            heap.Push(q, events[index][1])
            index++
        }
        
        if len(*q) == 0 && index == n {
            return res
        }
        
        for len(*q) > 0 {
            pre := heap.Pop(q).(int)
            if i <= pre {
                res++
                break
            }
        }
    }
    return res
}