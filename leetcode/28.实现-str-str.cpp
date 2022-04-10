/*
 * @Author: Opynicus
 * @Date: 2022-03-24 11:23:24
 * @LastEditTime: 2022-03-24 15:08:54
 * @LastEditors: Opynicus
 * @Description: leetcode string problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\28.实现-str-str.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.size(), nLen = needle.size();
        if (nLen == 0) {
            return 0;
        }
        vector<int> next(nLen);
        for (int i = 1, j = 0; i < nLen; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }
        for (int i = 0, j = 0; i < hLen; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == nLen) {
                return i - nLen + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

