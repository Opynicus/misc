/*
 * @Author: Opynicus
 * @Date: 2022-04-07 19:35:15
 * @LastEditTime: 2022-04-07 19:36:37
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\344.反转字符串.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int left = 0, right = s.size() - 1; left < right; left++, right--)
        {
            swap(s[left], s[right]);
        }
    }
};
// @lc code=end

