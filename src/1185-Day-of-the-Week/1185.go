func dayOfTheWeek(d int, m int, y int) string {
    weeks := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
    if (m < 3) {
        m += 12
        y--
    }
    return weeks[(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7]
}