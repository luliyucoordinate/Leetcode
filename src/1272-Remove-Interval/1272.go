func removeInterval(intervals [][]int, toBeRemoved []int) [][]int {
    res := make([][]int, 0)
    for _, inter := range intervals {
        if inter[0] >= toBeRemoved[1] || inter[1] <= toBeRemoved[0] {
            res = append(res, inter)
        } else {
            if inter[0] < toBeRemoved[0] {
                res = append(res, []int{inter[0], toBeRemoved[0]})
            } 
            if inter[1] > toBeRemoved[1] {
                res = append(res, []int{toBeRemoved[1], inter[1]})
            }
        }
    }
    return res
}