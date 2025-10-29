func smallestNumber(n int) int {
    t := 2
    for t <= n {
        t *= 2
    }
    return t - 1
}