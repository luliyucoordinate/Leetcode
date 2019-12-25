func isPossibleDivide(nums []int, k int) bool {
    if len(nums) % k != 0 {
        return false
    }
    sort.Ints(nums)
    cnt := make(map[int]int)
    for _, i := range nums {
        cnt[i]++
    }
    
    for _, i := range nums {
        t := cnt[i]
        if t > 0 {
            for j := i; j < i + k; j++ {
                if cnt[j] < t {
                    return false
                }
                cnt[j] -= t
            }
        }
    }
    return true
}