func largestUniqueNumber(A []int) int {
    sort.Ints(A)
    for len(A) > 1 && A[len(A)-1] == A[len(A)-2] {
        bk := A[len(A)-1]
        for len(A) > 0 && A[len(A)-1] == bk {
            A = A[:len(A)-1]
        }
    }
    if len(A) > 0 {
        return A[len(A)-1]
    }
    return -1
}