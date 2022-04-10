/*
 * @Author: Opynicus
 * @Date: 2022-01-13 15:05:46
 * @LastEditTime: 2022-01-13 15:06:32
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \leetcode\136.只出现一次的数字.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=136 lang=golang
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
func singleNumber(nums []int) int {
	ans := 0
	for i := range nums {
		ans ^= nums[i]
	}
	return ans
}
// @lc code=end

