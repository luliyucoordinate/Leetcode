func isRobotBounded(instructions string) bool {
    x, y, s := 0, 0, 0
    dire := [4][2]int{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}
    for _, c := range []byte(instructions) {
        switch c {
        case 'G':
            fmt.Println(x, y)
            x += dire[s][0]
            y += dire[s][1]
        case 'L':
            s = (s + 1) % 4
        case 'R':
            s = (s + 3) % 4
        }
    }
    return x == 0 && y == 0 || s > 0
}