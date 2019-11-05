type Leaderboard struct {
    d map[int]int
}


func Constructor() Leaderboard {
    return Leaderboard{d:make(map[int]int)}
}


func (this *Leaderboard) AddScore(playerId int, score int)  {
    this.d[playerId] += score
}


func (this *Leaderboard) Top(K int) int {
    q := make([]int, 0)
    for _, v := range this.d {
        q = append(q, v)
    }
    sort.Ints(q)
    res := 0
    for K > 0 {
        res += q[len(q) - K]
        K--
    }
    return res
}


func (this *Leaderboard) Reset(playerId int)  {
    delete(this.d, playerId)
}