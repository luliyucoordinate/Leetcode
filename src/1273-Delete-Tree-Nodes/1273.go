func deleteTreeNodes(n int, parent []int, value []int) int {
    for i := n - 1; i > 0; i-- {
        value[parent[i]] += value[i]
    }
    
    zeros := 0
    isZero := make([]bool, n)
    for i := 0; i < n; i++ {
        if parent[i] > 0 && isZero[parent[i]] || value[i] == 0 {
            isZero[i] = true
            zeros++
        }
    }
    return n - zeros
}