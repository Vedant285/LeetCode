func solve(sr int, sc int, image [][]int, temp int, color int) {
    image[sr][sc] = color 

    n := len(image)
    m := len(image[0])


    l := [4]int{0, 1, 0, -1}
    r := [4]int{1, 0, -1, 0}
    for i := 0; i < 4; i++ {
        nr := l[i] + sr
        nc := r[i] + sc

        if nr >= 0 && nc >= 0 && nr < n && nc < m && image[nr][nc] != color && image[nr][nc] == temp {
            solve(nr, nc, image, temp, color)
        }

    } 

}

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
    temp := image[sr][sc]
    solve(sr, sc, image, temp, color)

    return image
}