/*
 * @Author: Opynicus
 * @Date: 2022-01-11 16:02:27
 * @LastEditTime: 2022-01-11 16:13:49
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \leetcode\118.杨辉三角.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=118 lang=golang
 *
 * [118] 杨辉三角
 */

// @lc code=start
func generate(numRows int) [][]int {
	ans := make([][]int, numRows)
	for i := range ans {
		ans[i] = make([]int, i+1)
		ans[i][0], ans[i][i]= 1, 1
		for j := 1; j < i; j++ {
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1]
        }
	}
	return ans
}
// @lc code=end

