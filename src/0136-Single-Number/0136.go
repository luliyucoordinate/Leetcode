package main

func singleNumber(nums []int) int {
    ans := 0
    for _, val := range nums {
        ans ^= val
    }
    return ans
}
