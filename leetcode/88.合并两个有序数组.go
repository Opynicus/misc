/*
 * @Author: Opynicus
 * @Date: 2022-01-11 13:42:03
 * @LastEditTime: 2022-01-11 14:05:12
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \leetcode\88.合并两个有序数组.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=88 lang=golang
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
func merge(nums1 []int, m int, nums2 []int, n int)  {
	nums3 := make([]int, 0, m+n)
	i, j := 0, 0
	for  true {
		if i == m {
			nums3 = append(nums3, nums2[j:]...)
			break
		}
		if j == n {
			nums3 = append(nums3, nums1[i:]...)
			break
		}
		if nums1[i] < nums2[j] {
			nums3 = append(nums3, nums1[i])
			i++
		}
		if nums1[i] >= nums2[j] {
			nums3 = append(nums3, nums2[j])
			j++
		}
	}
	copy(nums1, nums3)
}
// @lc code=end

