func isMajorityElement(nums []int, target int) bool {
    cnt := 0
    for _, v := range nums {
        if target == v {
            cnt++
        }
    }
    return cnt > len(nums)/2
}