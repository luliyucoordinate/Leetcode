func displayTable(orders [][]string) [][]string {
    res := [][]string{}
    foods := []string{}
    hm := make(map[string]int)
    for _, order := range orders {
        food := order[2]
        if _, ok := hm[food]; !ok {
            foods = append(foods, food)
            hm[food] = 0
        }
    }
    
    sort.Strings(foods)
    hm = make(map[string]int)
    for i := 0; i < len(foods); i++ {
        hm[foods[i]] = i
    }
    
    a := make([][]int, 501)
    for _, order := range orders {
        table, _ := strconv.Atoi(order[1])
        if len(a[table]) == 0 {
            a[table] = make([]int, len(foods))
        }
        a[table][hm[order[2]]]++
    }
    row := []string{"Table"}
    row = append(row, foods...)
    res = append(res, row)
    
    for i := 0; i < 501; i++ {
        if len(a[i]) > 0 {
            row := []string{strconv.Itoa(i)}
            for j := 0; j < len(foods); j++ {
                row = append(row, strconv.Itoa(a[i][j]))
            }
            res = append(res, row)
        }
    }
    return res
}