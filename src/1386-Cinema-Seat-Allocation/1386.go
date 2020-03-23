func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
    cnt := make(map[int]int)
    for _, t := range reservedSeats {
        cnt[t[0]] |= 1 << (t[1] - 1)
    }
    
    res, q1, q2, q3, q4 := 0, 510, 480, 30, 120
    for _, v := range cnt {
        if q1 & v == 0 {
            res += 2
        } else if q2 & v == 0 || q3 & v == 0 || q4 & v == 0 {
            res++
        }
    }   
    return res + (n - len(cnt)) * 2
}