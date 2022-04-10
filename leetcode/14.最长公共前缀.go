/*
 * @Author: your name
 * @Date: 2022-01-06 16:51:55
 * @LastEditTime: 2022-01-06 17:18:16
 * @LastEditors: Please set LastEditors
 * @FilePath: \COP2000e:\leetcode\14.最长公共前缀.go
 */
/*
 * @lc app=leetcode.cn id=14 lang=golang
 *
 * [14] 最长公共前缀
 */

// @lc code=start
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	prefix := strs[0]
	for i := 1; i < len(strs); i++ {
		var curLen = len(strs[i])
		if len(prefix) < len(strs[i]) {
			curLen = len(prefix)
		} 
		idxn := 0
		for idxn < curLen &&  strs[0][idxn] == strs[i][idxn] {
			idxn++
		}
		prefix = prefix[:idxn]
		if len(prefix) == 0 {
            break
        }
	}
	return prefix
}
// @lc code=end

