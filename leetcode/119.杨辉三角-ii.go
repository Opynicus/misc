/*
 * @Author: Opynicus
 * @Date: 2022-01-13 14:17:35
 * @LastEditTime: 2022-01-13 14:19:35
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \leetcode\119.杨辉三角-ii.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=119 lang=golang
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
func getRow(rowIndex int) []int {
	ans := make([][]int, rowIndex+1)
	for i := range ans {
		ans[i] = make([]int, i+1)
		ans[i][0], ans[i][i]= 1, 1
		for j := 1; j < i; j++ {
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1]
        }
	}
	return ans[rowIndex]
}
// @lc code=end

