func largestMultipleOfThree(digits []int) string {
    cnt := make([]int, 10)
    for _, i := range digits {
        cnt[i]++
    }
    b1, b2 := cnt[1] + cnt[4] + cnt[7], cnt[2] + cnt[5] + cnt[8]
    t := (b1 + 2 * b2) % 3
    
    if t == 1 {
        if b1 >= 1 {
            b1--
        } else {
            b2 -= 2   
        }
    } else if t == 2 {
        if b2 >= 1 {
            b2--
        } else {
            b1 -= 2
        }
    }
    
    res := []byte{}
    for i := 9; i >= 0; i-- {
        if i % 3 == 0 {
            for cnt[i] > 0 {
                res = append(res, byte(i) + 48)
                cnt[i]--
            }
        } else if i % 3 == 1 {
            for cnt[i] > 0 && b1 > 0 {
                res = append(res, byte(i) + 48)
                cnt[i]--
                b1--
            }
        } else {
            for cnt[i] > 0 && b2 > 0 {
                res = append(res, byte(i) + 48)
                cnt[i]--
                b2--
            }
        }
    }
    
    if len(res) > 0 && res[0] == '0' {
        return "0"
    }
    return string(res)
}