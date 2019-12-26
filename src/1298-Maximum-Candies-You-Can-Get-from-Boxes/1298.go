func maxCandies(status []int, candies []int, keys [][]int, containedBoxes [][]int, initialBoxes []int) int {
    q, res := initialBoxes, 0
    for len(q) > 0 {
        changed := false
        for q_len := len(q); q_len > 0; q_len-- {
            b := q[0]
            q = q[1:]
            if status[b] == 1 {
                changed = true
                res += candies[b]
                q = append(q, containedBoxes[b]...)
                for _, i := range keys[b] {
                    status[i] = 1
                }
            } else {
                q = append(q, b)
            }
        }
        if !changed {
            return res
        }
    }
    return res
}