func distributeCandies(candies int, num_people int) []int {
    res := make([]int, num_people)
    step := 0
    for candies > 0 {
        res[step % num_people] += min(candies, step + 1)
        step++
        candies -= step
    }
    return res
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}