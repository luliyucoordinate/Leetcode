func checkIfExist(arr []int) bool {
    seen := make(map[int]int)
    for _, v := range arr {
        if _, ok := seen[v * 2]; ok {
            return true
        }
        if v % 2 == 0 {
            if _, ok := seen[v / 2]; ok {
                return true
            }
        }
        seen[v] = 1
    }
    return false
}