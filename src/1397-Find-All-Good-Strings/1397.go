const (
    M = 501
    N = 51
)
var dp [M][N][2][2]int
var ne [N]int

func findGoodStrings(n int, s1 string, s2 string, evil string) int {
    dp = [M][N][2][2]int{}
    ne = [N]int{}
    
    ne[0] = -1
    for i, j := 0, -1; i < len(evil); {
        for j != -1 && evil[i] != evil[j] {
            j = ne[j]
        }
        i++
        j++
        ne[i] = j
    }
    return dfs(s1, s2, evil, 0, 0, 1, 1)
}

func dfs(s1, s2, evil string, si, ei, lt, rt int) int {
    if ei == len(evil) {
        return 0
    } 
    
    if si == len(s1) {
        return 1
    }
    if dp[si][ei][lt][rt] > 0 {
        return dp[si][ei][lt][rt]
    } 
    
    l, r := byte('a'), byte('z')
    if lt > 0 {
        l = s1[si]
    }
    if rt > 0 {
        r = s2[si]
    }

    for i := l; i <= r; i++ {
        t := ei
        for t != -1 && evil[t] != i {
            t = ne[t]
        }
        
        nlt, nrt := lt, rt
        if i == l {
            nlt &= 1
        } else {
            nlt = 0
        }
        
        if i == r {
            nrt &= 1
        } else {
            nrt = 0
        }
        dp[si][ei][lt][rt] = (dp[si][ei][lt][rt] + 
                              dfs(s1, s2, evil, si + 1, t + 1, nlt, nrt)) % 1000000007
    }
    return dp[si][ei][lt][rt]
}