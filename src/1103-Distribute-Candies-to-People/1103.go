func distributeCandies(candies int, num_people int) []int {
    p := int((math.Sqrt(8 * float64(candies) + 1) - 1) / 2)
    R := candies - (p + 1) * p / 2
    r, c := p / num_people, p % num_people
    
    res := make([]int, num_people)
    for i := 0; i < num_people; i++ {
        res[i] = (2 * (i + 1) + (r - 1) * num_people) * r / 2
        if i < c {
            res[i] += i + 1 + r * num_people
        }
    }
    res[c] += R
    return res
}