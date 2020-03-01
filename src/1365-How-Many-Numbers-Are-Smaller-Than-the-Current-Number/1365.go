func smallerNumbersThanCurrent(nums []int) []int {
    cnt := make([]int, 101)
    res := make([]int, len(nums))
    for _, i := range nums {
        cnt[i]++
    }
    
    for i := 1; i < 101; i++ {
        cnt[i] += cnt[i - 1]
    }
    
    for i := 0; i < len(nums); i++ {
        if nums[i] != 0 {
            res[i] = cnt[nums[i] - 1]
        } 
    }
    return res
}