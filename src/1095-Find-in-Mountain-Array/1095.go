func bs(m *MountainArray, t, l, r int, asc bool) int {
    for l < r {
        mid := (l + r) >> 1
        if (asc && m.get(mid) >= t) || (!asc && m.get(mid) <= t) {
            r = mid
        } else {
            l = mid + 1
        }
    }
    if t == m.get(l) {
        return l
    }
    return -1
}

func findInMountainArray(target int, m *MountainArray) int {
    p, r := 0, m.length()-1
    for p < r {
        mid := (p + r) >> 1
        if m.get(mid) > m.get(mid+1) {
            r = mid
        } else {
            p = mid + 1
        }
    }
    i := bs(m, target, 0, p-1, true)
    if i != -1 {
        return i
    }
    return bs(m, target, p, m.length()-1, false)
}