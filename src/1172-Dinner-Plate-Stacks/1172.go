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

type DinnerPlates struct {
    q *IntHeap
    n int
    stacks [][]int
}


func Constructor(capacity int) DinnerPlates {
    this := new(DinnerPlates)
    this.q = new(IntHeap)
    this.n = capacity
    this.stacks = make([][]int, 0)
    return *this
}


func (this *DinnerPlates) Push(val int)  {
    for len(*this.q) > 0 && (*this.q)[0] < len(this.stacks) && len(this.stacks[(*this.q)[0]]) == this.n {
        heap.Pop(this.q)
    }
    if len(*this.q) == 0 {
        heap.Push(this.q, len(this.stacks))
    }
    if (*this.q)[0] == len(this.stacks) {
        this.stacks = append(this.stacks, []int{})
    }
    this.stacks[(*this.q)[0]] = append(this.stacks[(*this.q)[0]], val)
}


func (this *DinnerPlates) Pop() int {
    for len(this.stacks) > 0 && len(this.stacks[len(this.stacks)-1]) == 0 {
        this.stacks = this.stacks[:len(this.stacks)-1]
    }
    return this.PopAtStack(len(this.stacks) - 1)
}


func (this *DinnerPlates) PopAtStack(index int) int {
    if index >= 0 && index < len(this.stacks) && len(this.stacks[index]) > 0 {
        ret := this.stacks[index][len(this.stacks[index])-1]
        this.stacks[index] = this.stacks[index][:len(this.stacks[index])-1]
        heap.Push(this.q, index)
        return ret
    }
    return -1
}