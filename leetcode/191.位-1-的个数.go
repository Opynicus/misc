/*
 * @Author: Opynicus
 * @Date: 2022-01-17 12:49:07
 * @LastEditTime: 2022-01-17 13:00:10
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\191.位-1-的个数.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=191 lang=golang
 *
 * [191] 位1的个数
 */

// @lc code=start
func hammingWeight(num uint32) int {
    nums := 0
	for i := 0; i < 32; i++ {
        if (1 << i & num) != 0 {
            nums++
        }
    }
    return nums
}
// @lc code=end

