func angleClock(hour int, minutes int) float64 {
    t := abs(float64(hour)*30 + float64(minutes)/2.0 - float64(minutes)*6)
    return min(t, 360 - t)
}

func abs(a float64) float64 {
    if a < 0 {
        return -a
    }
    return a
}

func min(a, b float64) float64 {
    if a < b {
        return a
    }
    return b
}