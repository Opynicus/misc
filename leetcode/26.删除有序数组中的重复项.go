/*
 * @lc app=leetcode.cn id=26 lang=golang
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	numsLen := len(nums)
	if numsLen == 0 {
		return 0
	}
	cnt := 1
	for i := 0; i < numsLen - 1; i++ {
		if nums[i+1] != nums[i] {
			nums[cnt] = nums[i+1]
			cnt++
		}
	} 
	return cnt
}
// @lc code=end

