/*
 * @Author: your name
 * @Date: 2022-01-08 12:24:35
 * @LastEditTime: 2022-01-08 12:31:35
 * @LastEditors: Opynicus
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \leetcode\58.最后一个单词的长度.go
 */
/*
 * @lc app=leetcode.cn id=58 lang=golang
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
func lengthOfLastWord(s string) int {
	sLen := len(s)
	ans := 0
	for i := sLen - 1; i >= 0; i-- {
		if s[i] != ' ' {
			ans++
		} else if ans != 0 {
			return ans
		}
	}
	return ans
}
// @lc code=end

