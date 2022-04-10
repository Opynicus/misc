/*
 * @Author: Opynicus
 * @Date: 2022-01-08 12:39:57
 * @LastEditTime: 2022-01-08 12:46:49
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \leetcode\69.sqrt-x.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=69 lang=golang
 *
 * [69] Sqrt(x)
 */

// @lc code=start
func mySqrt(x int) int {
	if x <= 1 {
		return x
	}
	r := x
	for r > x / r {
		r = (r + x / r) / 2
	}
	return r
}
// @lc code=end

