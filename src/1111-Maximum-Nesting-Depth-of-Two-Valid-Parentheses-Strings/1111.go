func maxDepthAfterSplit(seq string) []int {
    res := make([]int, len(seq))
    for i, v := range []byte(seq) {
        if v == '(' {
            res[i] = i & 1
        } else {
            res[i] = 1 - i & 1
        }
    }
    return res
}