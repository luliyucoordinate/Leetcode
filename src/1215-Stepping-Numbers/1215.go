var res []int
var l, r int

func countSteppingNumbers(low int, high int) []int {
    res = make([]int, 0)
    l, r = low, high
    for i := 0; i <= 9; i++ {
        bfs(i)
    }
    sort.Sort(IntSlice(res))
    return res
}

func bfs(s int) {
    q := []int{s}
    for len(q) > 0 {
        pre := q[0]
        q = q[1:]
        if pre >= l && pre <= r {
            res = append(res, pre)
        }
        if pre == 0 || pre > r {
            continue
        }
        
        lt := pre % 10
        s1, s2 := pre * 10 + lt + 1, pre * 10 + lt - 1
        if lt == 0 {
            q = append(q, s1)
        } else if lt == 9 {
            q = append(q, s2)
        } else {
            q = append(q, s1)
            q = append(q, s2)
        }
    }
} 

type IntSlice []int

func (s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    return s[i] < s[j]
}