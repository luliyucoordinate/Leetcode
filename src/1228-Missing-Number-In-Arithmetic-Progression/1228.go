func missingNumber(arr []int) int {
    A := 0
    for _, v := range arr{
        A += v
    } 
    return (arr[0] + arr[len(arr)-1])*(len(arr) + 1)/2 - A
}