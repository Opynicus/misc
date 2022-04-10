/*
 * @Author: Opynicus
 * @Date: 2022-03-26 18:25:27
 * @LastEditTime: 2022-03-26 18:34:19
 * @LastEditors: Opynicus
 * @Description: KMP problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\28.实现-str-str.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=28 lang=golang
 *
 * [28] 实现 strStr()
 */

// @lc code=start
func strStr(haystack string, needle string) int {
	hLen, nLen := len(haystack), len(needle)
	if nLen == 0 {
		return 0;
	}
	next := make([]int, nLen)
	for i,j := 1, 0; i < nLen; i++ {
		for j != 0 && needle[i] != needle[j] {
			j = next[j-1]
		}
		if needle[i] == needle[j] {
			j++;
		}
		next[i] = j;
	}
	for i, j:= 0, 0; i < hLen; i++ {
		for j != 0 && haystack[i] != needle[j] {
			j = next[j-1]
		}
		if haystack[i] == needle[j] {
			j++;
		}
		if j == nLen {
			return i - nLen + 1;
		}
	}
	return -1;
}
// @lc code=end

