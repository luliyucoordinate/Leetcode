func numberOfDays(Y int, M int) int {
    D := []int{31,28,31,30,31,30,31,31,30,31,30,31}
    if Y % 400 == 0 || Y % 4 == 0 && Y % 100 != 0 { 
        D[1]++;
    }
    return D[M - 1];
}