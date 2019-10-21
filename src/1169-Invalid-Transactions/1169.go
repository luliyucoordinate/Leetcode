type tx struct {
    time int
    city string
    idx int
}

func invalidTransactions(transactions []string) []string {
    data := make(map[string][]tx)
    delt := make(map[int]int)
    for i, v := range transactions {
        it := strings.Split(v, ",")
        t, _ := strconv.Atoi(it[1])
        amout, _ := strconv.Atoi(it[2])
        if amout > 1000 {
            delt[i] = 0
        }
        data[it[0]] = append(data[it[0]], tx{time: t, city: it[3], idx: i})
    }
    
    for v, _ := range data {
        sort.Slice(data[v], func(i, j int) bool {
            return data[v][i].time < data[v][j].time
        })
        q := make([]tx, 0)
        for _, it := range data[v] {
            for len(q) > 0 && q[0].time < it.time - 60 {
                q = q[1:]
            }
            for _, ix := range q {
                if it.city != ix.city {
                    delt[it.idx], delt[ix.idx] = 0, 0
                }
            }
            q = append(q, it)
        }
    }
    res := []string{}
    for i, _ := range delt {
        res = append(res, transactions[i])
    }
    return res
}