/*
 * @Author: Opynicus
 * @Date: 2022-04-07 19:49:09
 * @LastEditTime: 2022-04-07 19:57:18
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\26.删除有序数组中的重复项.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, min = nums[0];
        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] > min)
            {
                nums[slow] = nums[fast];
                slow++;
                min = nums[fast];
            }
            
        }
        return slow;
    }
};
// @lc code=end

