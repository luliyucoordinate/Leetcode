type SnapshotArray struct {
    dif map[int]int
    snaps []map[int]int
}


func Constructor(length int) SnapshotArray {
    return SnapshotArray{dif:make(map[int]int), snaps:make([]map[int]int, 0)}
}


func (this *SnapshotArray) Set(index int, val int)  {
    this.dif[index] = val
}


func (this *SnapshotArray) Snap() int {
    newDif := make(map[int]int)
    for k, v := range this.dif {
        newDif[k] = v
    }
    this.snaps = append(this.snaps, newDif)
    return len(this.snaps) - 1
}


func (this *SnapshotArray) Get(index int, snap_id int) int {
    if _, ok := this.snaps[snap_id][index]; ok {
        return this.snaps[snap_id][index]
    }
    return 0
}