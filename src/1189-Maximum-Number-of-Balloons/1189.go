func maxNumberOfBalloons(text string) int {
    cnt := make([]int, 26)
    for i, _ := range text {
        cnt[text[i] - 'a']++
    }
    return min(min(min(min(cnt['l'-'a']/2, cnt['b'-'a']), cnt['a'-'a']), cnt['o'-'a']/2), cnt['n'-'a'])
}

func min(x, y int) int {
    if x < y {
        return x
    } else {
        return y
    }
}