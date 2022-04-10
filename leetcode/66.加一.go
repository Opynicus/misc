/*
 * @Author: Opynicus
 * @Date: 2022-01-10 14:02:53
 * @LastEditTime: 2022-01-10 14:49:16
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \leetcode\66.加一.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=66 lang=golang
 *
 * [66] 加一
 */

// @lc code=start
func plusOne(digits []int) []int {
	dLen := len(digits)
	if dLen == 0 {
		return digits
	}
	cnt := 0
	for i := dLen - 1; i >=0 ; i-- {
		if digits[i] == 9 {
			cnt++
		} else {
			cnt++
			break
		}
	}
	if cnt == 0 {
		digits[dLen-1]++
	} else if cnt == dLen && digits[0] == 9 {
		digits = make([]int, dLen + 1)
		digits[0] = 1
	} else {
		digits[dLen-cnt]++
		for i := dLen - cnt + 1; i < dLen; i++ {
			digits[i] = 0
		}
	}
	return digits
}
// @lc code=end

