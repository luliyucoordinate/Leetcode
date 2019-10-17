type NumArray struct {
    nums []int
    tree []int
}


func Constructor(data []int) NumArray {
    res := new(NumArray)
    res.nums = data
    res.tree = make([]int, len(data) + 1)
    for i := 0; i < len(data); i++ {
        res.update(i+1, data[i])
    }
    return *res
}

func (this *NumArray) update(i int, val int)  {
    for i < len(this.tree) {
        this.tree[i] += val
        i += this.lowbit(i)
    }
}

func (this *NumArray) query(i int) int {
    res := 0
    for i > 0 {
        res += this.tree[i]
        i -= this.lowbit(i)
    }
    return res
}

func (this *NumArray) lowbit(x int) int {
    return x & (-x)
}

func (this *NumArray) Update(i int, val int)  {
    this.update(i+1, val - this.nums[i])
    this.nums[i] = val
}


func (this *NumArray) SumRange(i int, j int) int {
    return this.query(j+1) - this.query(i)
}
