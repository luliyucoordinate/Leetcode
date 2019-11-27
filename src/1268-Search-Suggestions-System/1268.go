func suggestedProducts(products []string, searchWord string) [][]string {
    sort.Strings(products)
    res := make([][]string, 0)
    l, r := 0, len(products) - 1
    
    for i := 0; i < len(searchWord); i++ {
        for l <= r && (len(products[l]) <= i || products[l][i] != searchWord[i]) {
            l++
        }
        for l <= r && (len(products[r]) <= i || products[r][i] != searchWord[i]) {
            r--
        }
        
        tmp := make([]string, 0)
        for j := l; j < min(l + 3, r + 1); j++ {
            tmp = append(tmp, products[j])
        }
        res = append(res, tmp)
    }
    return res
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}