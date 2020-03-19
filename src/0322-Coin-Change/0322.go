var res int64

func coinChange(coins []int, amount int) int {
    sort.Ints(coins)
    res = int64(amount) + 1

    dfs(coins, len(coins) - 1, int64(amount), 0)
    if res > int64(amount) {
        return -1
    }
    return int(res)
}

func dfs(coins []int, index int, cur, cnt int64) {
    coins_i := int64(coins[index])
    if cnt + (cur + coins_i - 1) / coins_i >= res {
        return 
    }

    if cur % coins_i == 0 {
        res = cnt + cur / coins_i
        return
    }

    if index == 0 {
        return
    }

    for i := cur / coins_i; i >= 0; i-- {
        dfs(coins, index - 1, cur - coins_i * i, cnt + i)
    }
}