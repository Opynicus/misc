/*
 * @Author: Opynicus
 * @Date: 2022-01-13 14:49:41
 * @LastEditTime: 2022-01-13 14:54:18
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \leetcode\125.验证回文串.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=125 lang=golang
 *
 * [125] 验证回文串
 */

// @lc code=start
func isPalindrome(s string) bool {
	s = strings.ToLower(s)
	left, right := 0, len(s) - 1 
	for left < right  {
		for left < right && !isalnum(s[left]) {
            left++
        }
        for left < right && !isalnum(s[right]) {
            right--
        }
        if left < right {
            if s[left] != s[right] {
                return false
            }
            left++
            right--
        }
    }
    return true
}

func isalnum(ch byte) bool {
    return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')
}
// @lc code=end

