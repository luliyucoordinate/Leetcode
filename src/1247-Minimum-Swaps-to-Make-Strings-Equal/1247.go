func minimumSwap(s1 string, s2 string) int {
    x, y, n := 0, 0, len(s1)
    for i := 0; i < n; i++ {
        if s1[i] != s2[i] {
            if s1[i] == 'x' {
                x++
            } else {
                y++;
            }
        }
    }
    if (x + y) % 2 == 1 {
        return -1
    }
    return x / 2 + y / 2 + 2 * (x % 2)
}