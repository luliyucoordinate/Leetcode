type FloatHeap []float64

func (h FloatHeap) Len() int {
    return len(h)
}

func (h FloatHeap) Less(i, j int) bool {
    return h[i] < h[j]
}

func (h FloatHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *FloatHeap) Pop() interface{} {  
    x := (*h)[(*h).Len()-1]
	*h = (*h)[:(*h).Len()-1]
    return x
}

func (h *FloatHeap) Push(x interface{}) {  
    *h = append(*h, x.(float64))
}

func mincostToHireWorkers(q []int, w []int, K int) float64 {
    workers := make([][]float64, len(q))
    for i := 0; i < len(q); i++ {
        workers[i] = []float64{float64(w[i]) / float64(q[i]), float64(q[i])}
    }
    
    sort.Slice(workers, func(i, j int) bool {
        return workers[i][0] < workers[j][0]
    })
    var res, qsum float64
    res, qsum = 1000000000, 0
    pq := new(FloatHeap)
    
    for _, worker := range workers {
        qsum += worker[1]
        if len(*pq) == K - 1 {
            res = math.Min(res, qsum * worker[0])
        }
        heap.Push(pq, -worker[1])
        if len(*pq) >= K {
            qsum += heap.Pop(pq).(float64)
        }
    }
    return res
}