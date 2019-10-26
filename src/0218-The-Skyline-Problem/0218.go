type IntHeap [][]int

func (h IntHeap) Len() int {
    return len(h)
}

func (h IntHeap) Less(i, j int) bool {
    if h[i][0] == h[j][0] {
        return h[i][1] < h[j][1]
    }
    return h[i][0] < h[j][0]
}

func (h IntHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Pop() interface{} {  
    x := (*h)[(*h).Len()-1]
	*h = (*h)[:(*h).Len()-1]
    return x
}

func (h *IntHeap) Push(x interface{}) {  
    *h = append(*h, x.([]int))
}

func getSkyline(buildings [][]int) [][]int {
    const INT_MAX = int(^uint(0) >> 1)
    points := make([][]int, 0)
    rSet := make(map[int]int)
    for _, v := range buildings {
        points = append(points, []int{v[0], -v[2], v[1]})
        if _, ok := rSet[v[1]]; !ok {
            points = append(points, []int{v[1], 0, 0})
            rSet[v[1]] = 1
        }
    }
    sort.Slice(points, func(a, b int) bool {
        if points[a][0] == points[b][0] {
            return points[a][1] < points[b][1]
        }
        return points[a][0] < points[b][0]
    })
    h := new(IntHeap)
    heap.Push(h, []int{0, INT_MAX})
    res := [][]int{{0, 0}}
    for _, v := range points {
        for (*h)[0][1] <= v[0] {
            heap.Pop(h)
        }
        if v[1] != 0 {
            heap.Push(h, []int{v[1], v[2]})
        }
        if res[len(res) - 1][1] != -(*h)[0][0] {
            res = append(res, []int{v[0], -(*h)[0][0]})
        }
    }
    return res[1:len(res)]
}