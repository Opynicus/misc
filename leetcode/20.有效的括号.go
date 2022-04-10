/*
 * @Author: your name
 * @Date: 2022-01-07 12:10:30
 * @LastEditTime: 2022-01-07 12:52:17
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \COP2000e:\leetcode\20.有效的括号.go
 */
/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] 有效的括号
 */

// @lc code=start
func isValid(s string) bool {
	symStack := []byte{}
	sLen := len(s)
	symMap := map[byte]byte {')': '(', ']': '[', '}': '{'}
	for i := 0; i < sLen; i++ {
		if symMap[s[i]] == 0 {
			symStack = append(symStack, s[i])
		} else {
			if len(symStack) == 0 || symStack[len(symStack)-1] != symMap[s[i]] {
                return false
            }
            symStack = symStack[:len(symStack)-1]
		}
		
	}
	return len(symStack) == 0
}
// @lc code=end

