/*
 * @Author: Opynicus
 * @Date: 2022-04-20 15:37:59
 * @LastEditTime: 2022-04-20 15:52:55
 * @LastEditors: Opynicus
 * @Description: kmp problrm
 * @FilePath: \undefinedf:\github_repos\Leetcode_Solutions\459.重复的子字符串.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
// @lc code=end

