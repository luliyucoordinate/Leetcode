var s []byte
func parseBoolExpr(expression string) bool {
    s = []byte(expression)
    i := 0
    return parseStr(&i)
}

func parseStr(i *int) bool {
    if s[*i] == 't' {
        (*i)++
        return true
    } else if s[*i] == 'f' {
        (*i)++
        return false
    } else if s[*i] == '&' {
        return parseAnd(i)
    } else if s[*i] == '|' {
        return parseOr(i)
    } else {
        return parseNot(i)
    }
}

func parseAnd(i *int) bool {
    (*i) += 2
    res := parseStr(i)
    for s[*i] != ')' {
        (*i)++
        res = res && parseStr(i)
    }
    (*i)++
    return res
}

func parseOr(i *int) bool {
    (*i) += 2
    res := parseStr(i)
    for s[*i] != ')' {
        (*i)++
        res = res || parseStr(i)
    }
    (*i)++
    return res
}

func parseNot(i *int) bool {
    (*i) += 2
    res := !parseStr(i)
    (*i)++
    return res
}