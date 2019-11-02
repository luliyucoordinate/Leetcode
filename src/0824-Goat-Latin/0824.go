func toGoatLatin(S string) string {
    vowel := "aeiouAEIOU"
    vowels := make(map[rune]int)
    for _, c := range vowel {
        vowels[c]++
    }
    tokens := strings.Split(S, " ")
    res, i := "", 1
    for _, w := range tokens {
        res += " "
        if _, ok := vowels[rune(w[0])]; ok {
            res += w;
        } else {
            res += w[1:] + string(w[0])
        }
        res += "ma" + strings.Repeat("a", i)
        i++
    }
    return res[1:]
}