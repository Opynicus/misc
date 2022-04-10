/*
 * @Author: Opynicus
 * @Date: 2022-01-17 13:04:26
 * @LastEditTime: 2022-01-17 13:19:32
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\202.快乐数.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=202 lang=golang
 *
 * [202] 快乐数
 */

// @lc code=start
func isHappy(n int) bool {
	for i := 0; i < 100; i++ {
		res := 0
		for n > 0 {
			res += (n % 10) * (n % 10)
			n = n / 10
		}
		n = res
		if n == 1 {
			return true
		}
	}
	return false
}
// @lc code=end

