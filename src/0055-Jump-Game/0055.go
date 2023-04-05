package main

func canJump(nums []int) bool {
    power := nums[0] - 1
    for i := 1; i < len(nums); i++ {
        if power < 0 {
            return false
        }
        new_power := nums[i] - 1
        power--
        if new_power > power {
            power = new_power
        }
    }
    return true
}
