/*
 * @Author: Opynicus
 * @Date: 2022-02-10 14:14:02
 * @LastEditTime: 2022-02-10 14:26:18
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\389.找不同.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=389 lang=golang
 *
 * [389] 找不同
 */

// @lc code=start
func findTheDifference(s string, t string) byte {
	tnum := [26]int{}
	var ch byte
	for _, idx := range(s) {
		tnum[idx-'a']++
	}
	for _, idx := range(t) {
		tnum[idx-'a']--
		if tnum[idx-'a'] < 0 {
			ch = byte(idx)
			break
		}
	}
	return ch
}
// @lc code=end

