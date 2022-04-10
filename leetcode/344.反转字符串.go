/*
 * @Author: Opynicus
 * @Date: 2022-02-07 12:46:58
 * @LastEditTime: 2022-02-07 12:52:05
 * @LastEditors: Opynicus
 * @Description: letcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\344.反转字符串.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=344 lang=golang
 *
 * [344] 反转字符串
 */

// @lc code=start
func reverseString(s []byte)  {
	sLen := len(s)
	left, right := 0, sLen - 1
	for left < right {
		s[left], s[right] = s[right], s[left]
		left++
		right--
	}
}
// @lc code=end

