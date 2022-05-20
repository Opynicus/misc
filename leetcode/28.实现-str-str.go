/*
 * @lc app=leetcode.cn id=28 lang=golang
 *
 * [28] 实现 strStr()
 */

// @lc code=start
func strStr(haystack string, needle string) int {
	h_len, n_len := len(haystack), len(needle)
	if n_len == 0 {
		return 0
	}
	// build next array
	next := make([]int, n_len)
	for i, j := 1, 0; i < n_len && j < n_len; i++ {
		for j > 0 && needle[i] != needle[j] {
			j = next[j-1]
		}
		if needle[i] == needle[j] {
			j++
		}
		next[i] = j
	}
	// kmp
	for i, j := 0, 0; i < h_len && j < h_len; i++ {
		for j > 0 && haystack[i] != needle[j] {
			j = next[j-1]
		}
		if haystack[i] == needle[j] {
			j++
		}
		if j == n_len {
			return i - j + 1
		}
	}
	return -1
}

// @lc code=end

