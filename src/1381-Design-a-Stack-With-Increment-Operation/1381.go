type CustomStack struct {
    c int
    s, inc []int
}


func Constructor(maxSize int) CustomStack {
    this := new(CustomStack)
    this.c = maxSize
    this.s = []int{}
    this.inc = []int{}
    return *this
}


func (this *CustomStack) Push(x int)  {
    if len(this.s) < this.c {
        this.s = append(this.s, x)
        this.inc = append(this.inc, 0)
    }
}


func (this *CustomStack) Pop() int {
    if len(this.s) == 0 {
        return -1
    }
    
    if len(this.inc) > 1 {
        this.inc[len(this.inc) - 2] += this.inc[len(this.inc) - 1]
    }
    res := this.s[len(this.s) - 1] + this.inc[len(this.inc) - 1]
    this.s = this.s[:len(this.s) - 1]
    this.inc = this.inc[:len(this.inc) - 1]
    return res
}


func (this *CustomStack) Increment(k int, val int)  {
    if len(this.inc) > 0 {
        this.inc[min(k, len(this.inc)) - 1] += val
    }
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}