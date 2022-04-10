/*
 * @Author: Opynicus
 * @Date: 2022-02-10 14:41:30
 * @LastEditTime: 2022-02-10 14:59:41
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\392.判断子序列.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=392 lang=golang
 *
 * [392] 判断子序列
 */

// @lc code=start
func isSubsequence(s string, t string) bool {
	flag := false
	if s == "" {
		return true
	}
	var idx int
	for i, j := 0, 0; i < len(s) && j < len(t); {
		if s[i] == t[j] {
			i++
			j++
		} else {
			j++
		}
		idx = i
	}
	if idx == len(s) {
		flag = true
	}
	return flag
}
// @lc code=end

