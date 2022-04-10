/*
 * @Author: your name
 * @Date: 2022-01-08 11:44:08
 * @LastEditTime: 2022-01-08 11:53:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \leetcode\35.搜索插入位置.go
 */
/*
 * @lc app=leetcode.cn id=35 lang=golang
 *
 * [35] 搜索插入位置
 */

// @lc code=start
func searchInsert(nums []int, target int) int {
	nLen := len(nums)
	left, right := 0, nLen - 1
	ans := nLen
	for left <= right {
		mid := (right - left) / 2 + left
		if target <= nums[mid] {
			ans = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return ans
}
// @lc code=end

