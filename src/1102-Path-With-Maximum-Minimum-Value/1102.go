import "container/heap"
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

type Item struct {
    pre, x, y int
}

type Heap []*Item

func (h Heap) Len() int { 
    return len(h)
}

func (h Heap) Less(i, j int) bool {
    return h[i].pre > h[j].pre
}

func (h Heap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *Heap) Pop() interface{} {
    old := *h
    n := len(old)
    item := old[n - 1]
    *h = old[0:n - 1]
    return item
}

func (h *Heap) Push(x interface{}) {
    *h = append(*h, x.(*Item))
}

func maximumMinimumPath(A [][]int) int {
    r, c := len(A), len(A[0])
    dire := [4][2]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
    vi := make([][]int, r)
    for i := 0; i < r; i++ {
        vi[i] = make([]int, c)
    }
    vi[0][0] = 1
    
    q := &Heap{&Item{A[0][0], 0, 0}}
    heap.Init(q)
    for q.Len() > 0 {
        it := heap.Pop(q).(*Item)
        if it.x == r-1 && it.y == c-1 {
            return it.pre
        }
        for _, v := range dire {
            nx, ny := it.x + v[0], it.y + v[1]
            if nx >= 0 && nx < r && ny >= 0 && ny < c && vi[nx][ny] == 0 {
                vi[nx][ny] = 1
                heap.Push(q, &Item{min(it.pre, A[nx][ny]), nx, ny})
            } 
        }
    }
    return 0
}
