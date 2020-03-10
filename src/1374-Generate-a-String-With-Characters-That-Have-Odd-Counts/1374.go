func generateTheString(n int) string {
    res := []byte{}
    for i := 0; i < n - 1; i++ {
        res = append(res, 'a')
    }
    
    if n % 2 == 1 {
        res = append(res, 'a')
    } else {
        res = append(res, 'b')
    }
    return string(res)
}