/*
 * @Author: Opynicus
 * @Date: 2022-01-13 14:20:27
 * @LastEditTime: 2022-01-13 14:45:01
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \leetcode\121.买卖股票的最佳时机.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=121 lang=golang
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
func maxProfit(prices []int) int {
	minValue, maxProfit := prices[0], 0
	for i := range prices {
		maxProfit = max(maxProfit, prices[i] - minValue)
		minValue = min(prices[i], minValue)
	}
	return maxProfit
}
func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}
// @lc code=end

