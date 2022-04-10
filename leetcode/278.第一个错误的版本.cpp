/*
 * @Author: Opynicus
 * @Date: 2022-03-09 21:15:21
 * @LastEditTime: 2022-03-09 21:23:34
 * @LastEditors: Opynicus
 * @Description: leetcode binary search problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\278.第一个错误的版本.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            } 
        }
         return left;
    }
};
// @lc code=end

