func reverse(x int) int {
    var I_MAX, I_MIN int32 = int32(^uint32(0) >> 1)/10, (-1 << 31)/10
    var res, ix int32 = 0, int32(x)
    for ix != 0 {
        if res > I_MAX || res < I_MIN {
            return 0
        }
        
        tail := ix%10
        newR := res * 10 + tail
        if (newR - tail) / 10 != res {
            return 0
        }
        res = newR
        ix /= 10
    }
    return int(res)   
}