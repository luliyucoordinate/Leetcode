type FileSystem struct {
    paths map[string]int
}


func Constructor() FileSystem {
    res := new(FileSystem)
    res.paths = make(map[string]int)
    res.paths[""] = -1
    return *res
}


func (this *FileSystem) Create(path string, value int) bool {
    parent := path[:strings.LastIndex(path, "/")]
    if _, ok := this.paths[parent]; !ok {
        return false
    }
    this.paths[path] = value
    return true
}


func (this *FileSystem) Get(path string) int {
    if _, ok := this.paths[path]; !ok {
        return -1;
    }
    return this.paths[path];
}