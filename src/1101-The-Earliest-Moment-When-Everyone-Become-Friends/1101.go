var s []int

func earliestAcq(logs [][]int, N int) int {
	s = make([]int, N + 1)
	for i := 0; i <= N; i++ {
		s[i] = i
	}
	sort.Sort(IntSlice(logs))
	cnt := 0
	for _, v := range logs {
		rx, ry := find(v[1]), find(v[2])
		if rx != ry {
			s[rx] = ry
			cnt++
		}
		if cnt == N - 1 {
			return v[0]
		}
	}
	return -1
}
type IntSlice [][]int

func (s IntSlice) Len() int {
	return len(s)
}

func (s IntSlice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
	return s[i][0] < s[j][0]
}

func find(x int) int {
	if s[x] != x {
		s[x] = find(s[x])
	}
	return s[x]
}