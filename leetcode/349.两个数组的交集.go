/*
 * @Author: Opynicus
 * @Date: 2022-02-09 15:25:10
 * @LastEditTime: 2022-02-09 15:36:37
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\349.两个数组的交集.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=349 lang=golang
 *
 * [349] 两个数组的交集
 */

// @lc code=start
func intersection(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	var res []int
	for i, j := 0, 0; i < len(nums1) && j < len(nums2); {
		if nums1[i] == nums2[j] {
			if res == nil || res[len(res)-1] != nums1[i] {
				res = append(res, nums1[i])
			}
			i++
			j++
		} else if nums1[i] < nums2[j] {
			i++
		} else {
			j++
		}
	}
	return res
}
// @lc code=end

