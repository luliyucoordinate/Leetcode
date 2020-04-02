var N int

func numTeams(rating []int) int {
    N = 100000
    leftTree := make([]int, N + 1)
    rightTree := make([]int, N + 1)
    
    for _, r := range rating {
        update(rightTree, r, 1)
    }
    
    res := 0
    for _, r := range rating {
        update(rightTree, r, -1)
        res += getPrefixSum(leftTree, r - 1) * getSuffixSum(rightTree, r + 1) + 
                getSuffixSum(leftTree, r + 1) * getPrefixSum(rightTree, r - 1)
        update(leftTree, r, 1)
    }
    return res
}

func update(tr []int, x, v int) {
    for i := x; i <= N; i += i & -i {
        tr[i] += v
    }
}

func getPrefixSum(tr []int, x int) int {
    res := 0
    for i := x; i > 0; i -= i & -i {
        res += tr[i]
    }
    return res
}

func getSuffixSum(tr []int, i int) int {
    return getPrefixSum(tr, N) - getPrefixSum(tr, i - 1)
}