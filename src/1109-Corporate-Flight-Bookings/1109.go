func corpFlightBookings(bookings [][]int, n int) []int {
    res := make([]int, n + 1)
    for _, book := range bookings {
        res[book[0]-1] += book[2]
        res[book[1]] -= book[2]
    }
    for i := 1; i <= n; i++ {
        res[i] += res[i-1]    
    }
    return res[:n]
}