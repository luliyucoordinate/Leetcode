func xorQueries(arr []int, queries [][]int) []int {
    A := make([]int, len(arr) + 1)
    for i := 1; i <= len(arr); i++ {
        A[i] = A[i - 1] ^ arr[i - 1]
    }
    
    res := make([]int, len(queries))
    for i := 0; i < len(queries); i++ {
        res[i] = A[queries[i][0]] ^ A[queries[i][1] + 1]
    }
    return res
}