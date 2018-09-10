package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	nums_hash := map[int]int{}
	for i, num := range nums {
		dif := target - num
		if v, ok := nums_hash[dif]; ok {
			return []int{v, i}
		} 
		nums_hash[nums[i]] = i
	}
	return nil
}

func main() {
	nums := []int{1, 2, 3}
	target := 3
	fmt.Println(twoSum(nums, target))
}