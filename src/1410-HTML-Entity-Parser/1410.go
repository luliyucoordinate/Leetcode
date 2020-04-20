func entityParser(text string) string {
    entity := map[string]byte {
        "&quot": '"',
        "&apos": '\'',
        "&gt": '>',
        "&lt": '<',
        "&frasl": '/', 
        "&amp": '&',
    }
    n, i := len(text), 0
    var res strings.Builder
    
    for i < n {
        if text[i] == '&' {
            var t strings.Builder
            for text[i] != ';' {
                t.WriteByte(text[i])
                i++
            }
            
            if v, ok := entity[t.String()]; ok {
                res.WriteByte(v)
            } else {
                res.WriteString(t.String())
                res.WriteByte(';')
            }
        } else {
            res.WriteByte(text[i])
        }
        i++
    }
    return res.String()
}