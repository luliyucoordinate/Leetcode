type UndergroundSystem struct {
    check_in map[int]in
    check_out map[string][2]int
}

type in struct {
    station string
    time int
}

func Constructor() UndergroundSystem {
    return UndergroundSystem{check_in: make(map[int]in), check_out: make(map[string][2]int)}
}


func (this *UndergroundSystem) CheckIn(id int, stationName string, t int)  {
    this.check_in[id] = in{station: stationName, time: t}
}


func (this *UndergroundSystem) CheckOut(id int, stationName string, t int)  {
    start := this.check_in[id]
    name := start.station + ">" + stationName
    cur := this.check_out[name]
    this.check_out[name] = [2]int{cur[0] + t - start.time, cur[1] + 1}
}


func (this *UndergroundSystem) GetAverageTime(startStation string, endStation string) float64 {
    name := startStation + ">" + endStation
    return float64(this.check_out[name][0]) / float64(this.check_out[name][1])
}