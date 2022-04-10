/*
 * @Author: Opynicus
 * @Date: 2022-03-11 12:38:05
 * @LastEditTime: 2022-03-11 12:44:55
 * @LastEditors: Opynicus
 * @Description: leetcode two ptr problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\287.寻找重复数.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n;
        int ans = -1;
        while (left <= right)
        {
           int mid = left + (right -left) / 2;
           int cnt = 0;
           for (int i = 0; i < n; i++)
           {
              cnt += nums[i] <= mid;
           }
           if (cnt <= mid)
           {
               left = mid + 1;
           } else {
               right = mid - 1;
               ans = mid;
           }
        }
        return ans;
    }
};
// @lc code=end

