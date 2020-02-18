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

func isPossible(target []int) bool {
    var s int64 = 0
    h := new(IntHeap)
    for _, v := range target {
        s += int64(v)
        heap.Push(h, int64(v))
    }
    
    for true {
        pre := heap.Pop(h).(int64)
        s -= pre
        if pre == 1 || s == 1 {
            return true
        }
        if pre < s || pre % s == 0 {
            return false
        }
        
        pre %= s
        s += pre
        heap.Push(h, pre)
    }
    return false
}