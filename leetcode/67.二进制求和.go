/*
 * @Author: Opynicus
 * @Date: 2022-01-08 12:32:40
 * @LastEditTime: 2022-01-11 13:32:20
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \leetcode\67.二进制求和.go
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=67 lang=golang
 *
 * [67] 二进制求和
 */

// @lc code=start
func addBinary(a string, b string) string {
	ans := ""
    c := 0
    aLen, bLen := len(a), len(b)
    n := max(aLen, bLen)

    for i := 0; i < n; i++ {
        if i < aLen {
            c += int(a[aLen-i-1] - '0')
        }
        if i < bLen {
            c += int(b[bLen-i-1] - '0')
        }
        ans = strconv.Itoa(c%2) + ans
        c /= 2
    }
    if c > 0 {
        ans = "1" + ans
    }
    return ans
}

func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
// @lc code=end

