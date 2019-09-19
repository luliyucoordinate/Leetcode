func distanceBetweenBusStops(d []int, l int, r int) int {
    if l > r {
        l, r = r, l
    }
    k, v := 0, 0
    for i, t := range d {
        if i < l || i >= r {
            k += t
        } else {
            v += t
        }
    }
    
    return min(k, v)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}