type MajorityChecker struct {
    data []int
    indexs map[int][]int
}


func Constructor(arr []int) MajorityChecker {
    var res MajorityChecker
    res.indexs = make(map[int][]int)
    for i, v := range arr {
        res.data = append(res.data, v)
        res.indexs[v] = append(res.indexs[v], i)
    }
    return res
}


func (this *MajorityChecker) Query(left int, right int, threshold int) int {
	for i := 0; i < 8; i++ {
		var num int
		if right <= left {
			num = this.data[right]
		} else {
			num = this.data[rand.Intn(right - left) + left]
		}

		l, r := 0, len(this.indexs[num])-1
		for l < r {
			mid := (l + r) >> 1
			if this.indexs[num][mid] >= left {
				r = mid
			} else {
				l = mid + 1
			}
		}
		t1, t2 := l, 0

		l, r = 0, len(this.indexs[num])-1
		for l < r {
			mid := (l + r + 1) >> 1
			if this.indexs[num][mid] <= right {
				l = mid
			} else {
				r = mid - 1
			}
		}
		t2 = l + 1
		if t2 - t1 >= threshold {
			return num
		}
	}
	return -1
}