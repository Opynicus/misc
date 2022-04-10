/*
 * @Author: Opynicus
 * @Date: 2022-02-04 13:26:18
 * @LastEditTime: 2022-02-04 13:28:51
 * @LastEditors: Opynicus
 * @Description: leetcoce problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\326.3-的幂.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=326 lang=golang
 *
 * [326] 3 的幂
 */

// @lc code=start
func isPowerOfThree(n int) bool {
	for n > 0 && n % 3 == 0 {
		n /= 3
	}
	return n == 1
}
// @lc code=end

