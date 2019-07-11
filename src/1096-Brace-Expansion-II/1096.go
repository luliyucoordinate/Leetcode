var s []byte
func braceExpansionII(expression string) []string {
    s = []byte(expression + "}")
    i := 0
    res := solve(&i)
    sort.Strings(res)
    return res
}

func merge(a, b []string) []string {
    res := []string{}
    for _, l := range a {
        for _, r := range b {
            res  = append(res, l + r)
        }
    }
    return res
}

func solve(i *int) []string {
    if s[*i] != '{' {
        L := []string{string(s[*i])}
        (*i)++
        if s[*i] == '}' || s[*i] == ',' {
            return L
        }
        R := solve(i)
        return merge(L, R)
    }
    
    all := make(map[string]bool)
    for s[*i] != '}' {
        (*i)++
        R := solve(i)
        for _, it := range R {
            all[it] = true
        }
    }
    L := []string{}
    for k, _ := range all {
        L = append(L, k)
    }
    (*i)++
    if s[*i] == '}' || s[*i] == ',' {
        return L
    }
    R := solve(i)
    return merge(L, R)
}