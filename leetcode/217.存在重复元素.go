/*
 * @Author: Opynicus
 * @Date: 2022-01-28 13:08:34
 * @LastEditTime: 2022-01-28 13:26:28
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\217.存在重复元素.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=217 lang=golang
 *
 * [217] 存在重复元素
 */

// @lc code=start
func containsDuplicate(nums []int) bool {
	set := map[int]struct{}{}
	for _, v := range(nums) {
		if _, has := set[v]; has {
			return true
		}
		set[v] = struct{}{}
	}
	return false
}
// @lc code=end

