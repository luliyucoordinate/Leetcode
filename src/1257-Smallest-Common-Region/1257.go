func findSmallestRegion(regions [][]string, region1 string, region2 string) string {
    parent := make(map[string]string)
    for _, region := range regions {
        for _, r := range region[1:] {
            parent[r] = region[0]
        }
    }
    n1, n2 := region1, region2
    for n1 != n2 {
        if v, ok := parent[n1]; ok {
            n1 = v
        } else {
            n1 = region2
        }
        if v, ok := parent[n2]; ok {
            n2 = v
        } else {
            n2 = region1
        }
    }
    return n1
}