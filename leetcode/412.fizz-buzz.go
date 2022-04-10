/*
 * @Author: Opynicus
 * @Date: 2022-03-02 21:31:29
 * @LastEditTime: 2022-03-02 21:39:55
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\412.fizz-buzz.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=412 lang=golang
 *
 * [412] Fizz Buzz
 */

// @lc code=start
func fizzBuzz(n int) []string {
	ans := []string{}
	for i := 1; i <= n; i++ {
		if i % 3 == 0 && i % 5 != 0 {
			ans = append(ans, "Fizz")
		} else if i % 5 == 0 && i % 3 != 0 {
			ans = append(ans, "Buzz")
		} else if i % 15 == 0 {
			ans = append(ans, "FizzBuzz")
		} else {
			ans = append(ans, strconv.Itoa(i))
		}
	}
	return ans
}
// @lc code=end

