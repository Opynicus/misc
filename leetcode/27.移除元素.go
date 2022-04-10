/*
 * @Author: your name
 * @Date: 2022-01-08 11:37:06
 * @LastEditTime: 2022-01-08 11:42:55
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \leetcode\27.移除元素.go
 */
/*
 * @lc app=leetcode.cn id=27 lang=golang
 *
 * [27] 移除元素
 */

// @lc code=start
func removeElement(nums []int, val int) int {
	cnt := 0
	nLen := len(nums)
	for i := 0; i < nLen; i++ {
		if nums[i] != val {
			nums[cnt] = nums[i]
			cnt++
		}
	}
	return cnt
}
// @lc code=end

