func addNegabinary(arr1 []int, arr2 []int) []int {
    res := []int{}
    carry, l1, l2 := 0, len(arr1), len(arr2)
    
    for carry != 0 || l1 > 0 || l2 > 0 {
        if l1 > 0 {
            l1--
            carry += arr1[l1]
        }
        if l2 > 0 {
            l2--
            carry += arr2[l2]
        }
        res = append(res, carry & 1)
        carry = -(carry >> 1)
    }
    for len(res) > 1 && res[len(res) - 1] == 0 {
        res = res[:len(res) - 1]
    }
    reverse(res)
    return res
}

func reverse(a []int) {
    l, r := 0, len(a) - 1
    for l < r {
        a[l], a[r] = a[r], a[l]
        l++
        r--
    }
}