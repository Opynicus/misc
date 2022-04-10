/*
 * @Author: Opynicus
 * @Date: 2022-03-02 20:32:00
 * @LastEditTime: 2022-03-02 20:40:10
 * @LastEditors: Opynicus
 * @Description: leetcoe problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\242.有效的字母异位词.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int count = 0;
        int cnt[26] = {0};
        for (auto i : s) {
            cnt[i-'a']++;
        }
        for (auto i : t) {
            cnt[i-'a']--;
        }
        for (auto i : cnt) {
            if (i != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

