func canMeasureWater(x int, y int, z int) bool {
    if x + y < z {
        return false
    } 
    
    if x == 0 || y == 0 {
        return z == 0 || x + y == z
    } 
    return z % gcd(x, y) == 0
}

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}