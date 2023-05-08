package rotateimage

func rotate(matrix [][]int) {
	n, m := len(matrix), len(matrix[0])
	for i := 0; i < n; i++ {
		for j := i; j < m; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
		for j, k := 0, m-1; j < k; j, k = j+1, k-1 {
			matrix[i][j], matrix[i][k] = matrix[i][k], matrix[i][j]
		}
	}
}
