/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string revx = to_string(x);
        string tmp = revx;
        reverse(revx.begin(), revx.end());
        return revx == tmp;
    }
};
// @lc code=end

