type interval [][]int

func (s interval) Len() int {
	return len(s)
}

func (s interval) Less(i, j int) bool {
    if s[i][0] == s[j][0] {
        return s[i][1] < s[j][1]
    }
    return s[i][0] < s[j][0]
}

func (s interval) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func minMeetingRooms(intervals [][]int) int {
	if intervals == nil {
		return 0
	}
	tmp := make([][]int, 0)

	for _, v := range intervals {
		tmp = append(tmp, []int{v[0], 1})
		tmp = append(tmp, []int{v[1], -1})
	}

	sort.Sort(interval(tmp))
	res, n := 0, 0
	for _, v := range tmp {
		n += v[1]
		if res < n {
			res = n
		}
	}
	return res
}