var days []int

func daysBetweenDates(date1 string, date2 string) int {
    days = []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}   
    return abs(daysFrom1971(date1) - daysFrom1971(date2))
}

func check(y int) bool {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)
}

func daysFrom1971(dt string) int {
    y, _ := strconv.Atoi(dt[:4])
    m, _ := strconv.Atoi(dt[5:7])
    d, _ := strconv.Atoi(dt[8:])
    
    for i := 1971; i < y; i++ {
        if check(i) {
            d += 366
        } else {
            d += 365
        }
    }
    
    for i := 0; i < m - 1; i++ {
        d += days[i]
    }
    
    if m > 2 && check(y) {
        d++
    }
    return d
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}