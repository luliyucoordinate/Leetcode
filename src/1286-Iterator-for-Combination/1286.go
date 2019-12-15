type CombinationIterator struct {
    res []string
}

func Constructor(ch string, l int) CombinationIterator {
    data := make([]string, 0)
    combine(0, l, "", ch, &data)
    return CombinationIterator{res:data}
}

func combine(s, l int, cur, ch string, data *[]string) {
    if len(cur) == l {
        *data = append(*data, cur)
        return
    }
    
    for i := s; i <= len(ch) - (l - len(cur)); i++ {
        combine(i + 1, l, cur + string(ch[i]), ch, data)
    }
}


func (this *CombinationIterator) Next() string {
    ret := this.res[0]
    this.res = this.res[1:]
    return ret
}


func (this *CombinationIterator) HasNext() bool {
    return len(this.res) != 0
}