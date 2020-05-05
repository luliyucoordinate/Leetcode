func numberWays(hats [][]int) int {
    n, mod := len(hats), 1000000007
    f := make([][]int, 2)
    for i := 0; i < 2; i++ {
        f[i] = make([]int, 1024)
    }
    f[0][0] = 1
    
    a := make([][]int, 41)
    for i := 0; i < n; i++ {
        for _, hat := range hats[i] {
            a[hat] = append(a[hat], i)
        }
    }
    
    for i := 1; i <= 40; i++ {
        for j := 0; j < (1 << n); j++ {
            f[i % 2][j] = f[(i - 1) % 2][j];
            for _, x := range a[i] {
                if ((j >> x) & 1) != 0 {
                    f[i % 2][j] += f[(i - 1) % 2][j ^ (1 << x)];
                    f[i % 2][j] %= mod;
                }
            }
        }
    }
    return f[0][(1 << n) - 1]
}