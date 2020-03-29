func findLucky(arr []int) int {
    cnt := make([]int, 501)
    for _, i := range arr {
        cnt[i]++
    }
    
    for i := 500; i > 0; i-- {
        if cnt[i] == i {
            return i
        }
    }
    return -1
}