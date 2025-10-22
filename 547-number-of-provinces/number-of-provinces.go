func check(i int, mat [][]int, vis []int, n int) {
    vis[i] = 1
    
    for k := 0; k < n; k++{
        if mat[i][k] == 1  && vis[k] == 0  {
            check(k, mat, vis, n)
        }
    }
}

func findCircleNum(isConnected [][]int) int {
    n := len(isConnected)

    vis := make([]int, n)
    
    cnt := 0
    for i := 0; i < n; i++ {
        if vis[i] == 0 {
            check(i, isConnected, vis, n)
            cnt++
        }
    } 
    return cnt

}