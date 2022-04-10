/*
 * @Author: Opynicus
 * @Date: 2022-01-06 15:08:10
 * @LastEditTime: 2022-01-07 18:06:22
 * @LastEditors: Opynicus
 * @FilePath: \undefinede:\leetcode\1.两数之和.go
 */
/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if (nums[i] + nums[j] == target) {
				return []int {i, j}
			}
		}
	}
	return nil;
}
// @lc code=end

