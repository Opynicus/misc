/*
 * @Author: Opynicus
 * @Date: 2022-04-07 20:01:27
 * @LastEditTime: 2022-04-07 20:13:29
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\88.合并两个有序数组.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j, k;
        vector<int> tmp(m+n);
        for (i = 0, j = 0, k = 0; i < m && j < n; k++)
        {
            if (nums1[i] <= nums2[j])
            {
                tmp[k] = nums1[i];
                i++;
            }
            else
            {
                tmp[k] = nums2[j];
                j++;
            }
        }
        while (i < m)
        {
            tmp[k] = nums1[i];
            k++;
            i++;
        }
        while (j < n)
        {
            tmp[k] = nums2[j];
            k++;
            j++;
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = tmp[i];
        }
        
    }
};
// @lc code=end

