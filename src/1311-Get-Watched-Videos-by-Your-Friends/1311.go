var cnt map[string]int 

func watchedVideosByFriends(watchedVideos [][]string, friends [][]int, id int, level int) []string {
    seen := make([]int, len(friends))
    q := []int{id}
    seen[id] = 1
    
    for level > 0 {
        for i := len(q); i > 0; i-- {
            idx := q[0]
            q = q[1:]
            for _, p := range friends[idx] {
                if seen[p] == 0 {
                    seen[p] = 1
                    q = append(q, p)
                }
            }
        }
        level--
    }
    
    cnt = make(map[string]int)
    for _, v := range q {
        for _, s := range watchedVideos[v] {
            cnt[s]++
        }
    }
    
    res := []string{}
    for k := range cnt {
        res = append(res, k)
    }
    sort.Sort(strSlice(res))
    return res
}

type strSlice []string

func (x strSlice) Len() int { return len(x) }
func (x strSlice) Swap(i, j int) { x[i], x[j] = x[j], x[i] }
func (x strSlice) Less(i, j int) bool {
    if cnt[x[i]] == cnt[x[j]] {
        return x[i] < x[j]
    }
    return cnt[x[i]] < cnt[x[j]]
}
