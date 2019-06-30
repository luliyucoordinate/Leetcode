func minHeightShelves(books [][]int, shelf_width int) int {
    n, INF := len(books), 1000*1000
    mem := make([]int, n + 1)
    for i := 1; i <= n; i++ {
        mem[i] = INF
    }
    
    for i := 1; i <= n; i++ {
        w, h := 0, 0
        for j := i - 1; j >= 0; j-- {
            w += books[j][0]
            if w > shelf_width {
                break
            }
            if h < books[j][1] {
                h = books[j][1]
            }
            if mem[j] + h < mem[i] {
                mem[i] = mem[j] + h
            }
        }
    }
    return mem[n]
}