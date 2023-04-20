package containerwithmostwater

func maxArea(height []int) int {
    l, r, res := 0, len(height)-1, 0
    for l < r {
        res = max(res, (r - l)*min(height[l], height[r]))
        if height[l] > height[r] {
            r--
        } else {
            l++
        }
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}