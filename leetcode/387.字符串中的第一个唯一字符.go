/*
 * @Author: Opynicus
 * @Date: 2022-03-02 17:33:48
 * @LastEditTime: 2022-03-02 17:40:26
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\387.字符串中的第一个唯一字符.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=387 lang=golang
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
func firstUniqChar(s string) int {
	chs := [26]int{}
	for _, c := range(s) {
		chs[c-'a']++
	}
	for i, j := range(s) {
		if chs[j-'a'] == 1 {
			return i
		}
	}
	return -1
}
// @lc code=end

