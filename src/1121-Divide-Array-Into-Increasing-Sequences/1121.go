func canDivideIntoSubsequences(nums []int, K int) bool {
    mCnt := 0
    counts := make(map[int]int)
    
    for _, n := range nums {
        counts[n]++
        if counts[n] > mCnt {
            mCnt = counts[n]
        }
    }
    
    if mCnt * K > len(nums) {
        return false
    }
    return true
}