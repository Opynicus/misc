/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& i: matrix) {
            auto i_mid = lower_bound(i.begin(), i.end(), target);
            if (i_mid != i.end() && *i_mid == target) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end