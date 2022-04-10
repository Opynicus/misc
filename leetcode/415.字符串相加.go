/*
 * @Author: Opynicus
 * @Date: 2022-02-26 09:44:59
 * @LastEditTime: 2022-02-26 09:55:10
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\415.字符串相加.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=415 lang=golang
 *
 * [415] 字符串相加
 */

// @lc code=start
func addStrings(num1 string, num2 string) string {
	ans := ""
	carry := 0
	for i, j := len(num1) - 1, len(num2) - 1; i >= 0 || j >= 0 || carry != 0; i, j = i - 1, j - 1 {
		x, y := 0, 0
		if i >= 0 {
			x = int(num1[i] - '0')
		}
		if j >= 0 {
			y = int(num2[j] - '0')
		}
		result := x + y + carry
        ans = strconv.Itoa(result % 10) + ans
        carry = result / 10
	}
	return ans
}
// @lc code=end

