func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) []int {
    data := make([][]int, 0)
    for _, s := range restaurants {
        if s[2] >= veganFriendly && s[3] <= maxPrice && s[4] <= maxDistance {
            data = append(data, s)
        }
    }
    
    sort.Slice(data, func(i, j int) bool {
        if data[i][1] == data[j][1] {
            return data[i][0] > data[j][0]
        }
        return data[i][1] > data[j][1]
    })
    
    res := make([]int, len(data))
    for i, s := range data {
        res[i] = s[0]
    }
    return res
}