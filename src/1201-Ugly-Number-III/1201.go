func nthUglyNumber(n int, a int, b int, c int) int {
    var l, r int64
    l, r = 1, 2000000000
    for l < r {
        mid := (l + r) >> 1
        if cnt(mid, int64(a), int64(b), int64(c)) < int64(n) {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return int(l)
}

func gcd(x, y int64) int64 {
    for y > 0 {
        x, y = y, x % y
    }
    return x
}

func lcm2(x, y int64) int64 {
    return x * y / gcd(x, y)
}

func lcm3(x, y, z int64) int64 {
    res := x * y / gcd(x, y)
    return res * z / gcd(res, z)
}

func cnt(k, x, y, z int64) int64 {
    return k/x + k/y + k/z - k/lcm2(x, y) -k/lcm2(x, z) - k/lcm2(y, z) + k/lcm3(x, y, z)
}