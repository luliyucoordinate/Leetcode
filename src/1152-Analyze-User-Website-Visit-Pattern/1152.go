func mostVisitedPattern(username []string, timestamp []int, website []string) []string {
    data, n := make(map[string]map[string]int), len(username)
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if timestamp[i] < timestamp[j] && username[i] == username[j] {
                for k := 0; k < n; k++ {
                    if timestamp[j] < timestamp[k] && username[j] == username[k] {
                        ts := website[i] + "," + website[j] + "," + website[k]
                        if _, ok := data[ts]; !ok {
                            data[ts] = make(map[string]int)
                        }
                        data[ts][username[k]]++
                    }     
                }
            }
        }
    }
    var s1 []string
    for k := range data {
        s1 = append(s1, k)
    }
    sort.Strings(s1)
    res, s := "", 0
    for _, v := range s1 {
        if len(data[v]) > s {
            s = len(data[v])
            res = v
        }
    }
    return strings.Split(res, ",")
}