import "math"

func pathInZigZagTree(label int) []int {
    res := []int{}
    for true {
        res = append(res, label)
        if label == 1 {
            break
        }
        label = label >> 1
        label = label ^ (1 << uint(math.Log2(float64(label))) - 1)
    }
    return reverse(res)
}

func reverse(s []int) []int {
    for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
        s[i], s[j] = s[j], s[i]
    }
    return s
}