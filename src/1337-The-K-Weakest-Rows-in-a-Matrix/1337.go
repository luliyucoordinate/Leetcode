
func kWeakestRows(mat [][]int, k int) []int {
    data := [][]int{}
    for i := 0; i < len(mat); i++ {
        data = append(data, []int{numOnes(mat[i]), i})
    }
    
    sort.Slice(data, func(i, j int) bool {
        if data[i][0] == data[j][0] {
            return data[i][1] < data[j][1]
        }
        return data[i][0] < data[j][0]
    })
    res := []int{}
    for i := 0; i < k; i++ {
        res = append(res, data[i][1])
    }
    return res
}

func numOnes(row []int) int {
    l, r := 0, len(row)
    for l < r {
        mid := (l + r) >> 1
        if row[mid] == 1 {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return l
}