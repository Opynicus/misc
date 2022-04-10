/*
 * @Author: Opynicus
 * @Date: 2022-02-09 17:05:52
 * @LastEditTime: 2022-02-09 17:20:55
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\383.赎金信.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=383 lang=golang
 *
 * [383] 赎金信
 */

// @lc code=start
func canConstruct(ransomNote string, magazine string) bool {
	cNums := [26]int{}
	mNums := [26]int{}
	for _, idx := range(magazine) {
		cNums[idx-'a']++
	}
	for _, idx := range(ransomNote) {
		mNums[idx-'a']++
		if cNums[idx-'a'] < mNums[idx-'a'] {
			return false
		}
	}
	return true
}
// @lc code=end

