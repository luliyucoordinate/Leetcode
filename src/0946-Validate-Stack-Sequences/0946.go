func validateStackSequences(pushed []int, popped []int) bool {
    i, j := 0, 0
    
    for _, v := range pushed {
        pushed[i] = v
        i++
        for i > 0 && pushed[i - 1] == popped[j] {
            i--
            j++
        }
    }
    
    return i == 0
}