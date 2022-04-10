/*
 * @Author: Opynicus
 * @Date: 2022-01-08 12:53:25
 * @LastEditTime: 2022-01-08 12:55:52
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \leetcode\70.爬楼梯.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=70 lang=golang
 *
 * [70] 爬楼梯
 */

// @lc code=start
func climbStairs(n int) int {
	a, b, c :=0, 0, 1
	for i := 1; i <= n; i++ {
		a = b
		b = c
		c = a + b
	}
	return c
}
// @lc code=end

