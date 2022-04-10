/*
 * @Author: Opynicus
 * @Date: 2022-01-06 15:25:30
 * @LastEditTime: 2022-01-07 18:06:46
 * @LastEditors: Opynicus
 * @FilePath: e:\leetcode\13.罗马数字转整数.go
 */
 
/*
 * @lc app=leetcode.cn id=13 lang=golang
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
func romanToInt(s string) int {
	var sum int
	var HashMap = map[byte]int {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
	for i :=range s {
		var curValue = HashMap[s[i]]
		if i < len(s) - 1 && curValue < HashMap[s[i+1]] {
			sum -= curValue
		} else {
			sum += curValue
		}
	}
	return sum
}
// @lc code=end

