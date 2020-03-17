type IntHeap []int64

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
    *h = append(*h, x.(int64))
}

func maxPerformance(n int, s []int, e []int, k int) int {
    engineers := make([][]int64, n)
    for i := 0; i < n; i++ {
        engineers[i] = []int64{int64(e[i]), int64(s[i])}
    }
    
    sort.Slice(engineers, func(i, j int) bool {
        return engineers[i][0] > engineers[j][0]
    })
    var res, sSum int64
    res, sSum = 0, 0
    pq := new(IntHeap)
    
    for _, engineer := range engineers {
        sSum += engineer[1]
        res = max(res, sSum * engineer[0])
        heap.Push(pq, engineer[1])
        if len(*pq) >= k {
            sSum -= heap.Pop(pq).(int64)
        }
    }
    return int(res % 1000000007)
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}