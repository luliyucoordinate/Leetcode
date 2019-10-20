func minAvailableDuration(A [][]int, B [][]int, duration int) []int {
    sort.Sort(IntSlice(A))
    sort.Sort(IntSlice(B))
    i, j := 0, 0
    for i < len(A) && j < len(B) {
        l := max(A[i][0], B[j][0])
        r := min(A[i][1], B[j][1])
        if l + duration <= r {
            return []int{l, l + duration};
        }
        if A[i][1] < B[j][1] {
            i++
        } else {
            j++
        }
    }
    return []int{}
}

type IntSlice [][]int

func (s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    if s[i][0] != s[j][0] {
        return s[i][0] < s[j][0]
    }
    return s[i][1] < s[j][1]
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}